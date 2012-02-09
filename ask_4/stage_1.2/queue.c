/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : queue.c

* Purpose :

* Creation Date : 21-01-2012

* Last Modified : Thu 09 Feb 2012 11:26:03 AM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/
#include "queue.h"

void insert(pid_t pid, sid_t id, queue *q)
{
    /*
     * insert a new pid in the queue
     * before q 
     * this way it is appended at the end
     * for round robin implementation
     */
    if( q->pid != 0 )
    {
        queue *nq = ( queue *) malloc ( sizeof( queue ) );
        if( nq == NULL )
        {
            perror("queue:insert, bad allocation");
            exit(EXIT_FAILURE);
        }
        nq->next = q;
        nq->prev = q->prev;
        (q->prev)->next = nq;
        q->prev = nq;
        nq->pid = pid;
        nq->id = id;
    }
    else
    {
        q->pid = pid;
        q->id = id;
    }
}

inline
queue * next_q(queue *q)
{
    /*
     * returns the next element
     * in the queue
     */
    return q->next;
}

queue * remove_q(queue *q)
{
    /* 
     * deletes an element and
     * returns the next one
     */
    queue *p = q -> prev;
    p -> next = q -> next;
    p = p -> next;
    p -> prev = q -> prev;
    if ( p -> pid == q -> pid )
    {
        free(q);
        return NULL;
    }
    free(q);
    return p;
}

void init_q(queue *head) 
{
    /*
     * initialize the queue
     */
    head->pid = 0;
    head->id  = 0;
    head->prev = head;
    head->next = head;
}

void print_q(queue *q,int len)
{
    int i;
    for ( i = 0 ; i < len ; ++i )
    {
        printf("%d <- %d -> %d\n",q->prev->id,q->id,q->next->id);
        q=next_q(q);
    }
}

queue *find_q( sid_t id,queue *q, int len )
{
    queue *buf = q;
    int i;
    for( i = 0 ; i < len ; ++i )
    {
        if ( buf->id == id )
        {
            return buf;
        }
        buf = next_q( buf );
    }
    return NULL;
}

queue *find_q_with_pid( pid_t pid,queue *q, int len )
{
    queue *buf = q;
    int i;
    for( i = 0 ; i < len ; ++i )
    {
        if ( buf->pid == pid )
        {
            return buf;
        }
        buf = next_q( buf );
    }
    return NULL;
}
