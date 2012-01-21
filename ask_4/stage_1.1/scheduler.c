#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <assert.h>

#include <sys/wait.h>
#include <sys/types.h>

#include "proc-common.h"
#include "request.h"
#include "queue.h"

/* Compile-time parameters. */
#define SCHED_TQ_SEC 2                /* time quantum */
#define TASK_NAME_SZ 60               /* maximum size for a task's name */


queue *current_proc;
queue *last_elem;
/* SIGALRM handler: Gets called whenever an alarm goes off.
 * The time quantum of the currently executing process has expired,
 * so send it a SIGSTOP. The SIGCHLD handler will take care of
 * activating the next in line.
 */
static void
sigalrm_handler(int signum)
{
    /*
     * Stop currently running process
     * This will spawn SIGCHLD when the
     * child is stopped
     */
    if ( current_proc != NULL )
    {
        kill( current_proc->pid, SIGSTOP );
        current_proc = next_q( current_proc );
        kill( current_proc->pid, SIGCONT );
        printf("NEEEEEEEEEEXT\n");
        alarm( SCHED_TQ_SEC );
    }
}

/* SIGCHLD handler: Gets called whenever a process is stopped,
 * terminated due to a signal, or exits gracefully.
 *
 * If the currently executing task has been stopped,
 * it means its time quantum has expired and a new one has
 * to be activated.
 */
static void
sigchld_handler(int signum)
{
    int status;
    if ( current_proc != NULL && waitpid( current_proc->pid, &status, WNOHANG ) == current_proc->pid  )
    {
        print_q(current_proc,4);
        current_proc = remove_q( current_proc );
        printf("i just died in your arms tonight\n");
    }
}

/* Install two signal handlers.
 * One for SIGCHLD, one for SIGALRM.
 * Make sure both signals are masked when one of them is running.
 */
static void
install_signal_handlers(void)
{
    sigset_t sigset;
    struct sigaction sa;

    sa.sa_handler = sigchld_handler;
    sa.sa_flags = SA_RESTART ;
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGCHLD);
    sigaddset(&sigset, SIGALRM);
    sa.sa_mask = sigset;
    if (sigaction(SIGCHLD, &sa, NULL) < 0) {
        perror("sigaction: sigchld");
        exit(1);
    }

    sa.sa_handler = sigalrm_handler;
    if (sigaction(SIGALRM, &sa, NULL) < 0) {
        perror("sigaction: sigalrm");
        exit(1);
    }

    /*
     * Ignore SIGPIPE, so that write()s to pipes
     * with no reader do not result in us being killed,
     * and write() returns EPIPE instead.
     */
    if (signal(SIGPIPE, SIG_IGN) < 0) {
        perror("signal: sigpipe");
        exit(1);
    }
}


void child ( char *ex )
{
    char chld_name[TASK_NAME_SZ];
    snprintf( chld_name, TASK_NAME_SZ, "%s", ex );
    chld_name[strnlen(chld_name,TASK_NAME_SZ)]='\0';
    char *newargv[] = { chld_name, NULL, NULL, NULL };
    char *newenviron[] = { NULL };
    change_pname(chld_name);
    raise(SIGSTOP);
    execve(chld_name, newargv, newenviron);
    perror("execve");
    exit(1);
}


int main(int argc, char *argv[])
{
    int nproc;
    /*
     * For each of argv[1] to argv[argc - 1],
     * create a new child process, add it to the process list.
     */
    /*
     * initialize queue for procs
     */
    queue *proc_head = (queue *) malloc( sizeof(queue) );
    queue *current;
    current_proc = proc_head;
    current=proc_head;
    init_q( current );

    nproc = argc-1; /* number of proccesses goes here */
    pid_t p;

    int i;
    for ( i = 0 ; i < nproc ; ++i )
    {
        p = fork();

        if ( p == 0 )
        {
            child( argv[i+1] );
            exit(1);
        }
        else
        {
           current = insert(p,current);
        }
    }
    print_q(proc_head,5);

    /* Wait for all children to raise SIGSTOP before exec()ing. */
    wait_for_ready_children(nproc);

    sleep(1);
    /* Install SIGALRM and SIGCHLD handlers. */
    install_signal_handlers();

    if (nproc == 0) {
        fprintf(stderr, "Scheduler: No tasks. Exiting...\n");
        exit(1);
    }


    /* loop forever  until we exit from inside a signal handler. */

    /* start the first of my children */
    //kill( children[ running ], SIGCONT );
    /* set my alarm */
    alarm(SCHED_TQ_SEC);
    while (pause())
        ;

    /* Unreachable */
    fprintf(stderr, "Internal error: Reached unreachable point\n");
    return 1;
}
