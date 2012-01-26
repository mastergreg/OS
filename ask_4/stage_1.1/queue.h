/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : queue.h

* Purpose :

* Creation Date : 21-01-2012

* Last Modified : Sat 21 Jan 2012 09:28:47 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/
#ifndef QUEUE_H
#define QUEUE_H 
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct __queue queue;
struct __queue {
    pid_t pid;
    queue * prev;
    queue * next;
};

void init_q(queue *head);
void print_q(queue *q,int len);
queue *insert(pid_t pid, queue *q);
queue *remove_q(queue *q);
queue *next_q(queue *q);
#endif