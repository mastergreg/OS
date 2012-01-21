/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : queue.c

* Purpose :

* Creation Date : 21-01-2012

* Last Modified : Sun 22 Jan 2012 01:51:50 AM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/
#include "queue.h"

queue *insert(pid_t pid, queue *q)
{
    if( q->pid != 0 )
    {
        queue *nq = ( queue *) malloc ( sizeof( queue ) );
        nq->prev = q;
        nq->next = q->next;
        q->next = nq;
        (nq->next)->prev = nq;
        nq->pid = pid;
        return nq;
    }
    q->pid = pid;
    return q;
}

inline
queue *next_q(queue *q)
{
    return q->next;
}

queue *remove_q(queue *q)
{
    queue *p = q->prev;
    p->next = q->next;
    p = q->next;
    p->prev = q->prev;
    if ( p->pid == q->pid )
    {
        free(q);
        return NULL;
    }
    free(q);
    return p;
}
void init_q(queue *head) {
    head->pid=0;
    head->prev=head;
    head->next=head;
}
void print_q(queue *q,int len)
{
    int i;
    for ( i = 0 ; i < len ; ++i )
    {
        printf("%p <- %p -> %p\n",q->prev,q,q->next);
        q=next_q(q);
    }
}
