/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : queue.h

* Purpose :

* Creation Date : 21-01-2012

* Last Modified : Thu 09 Feb 2012 01:54:29 AM EET

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
    int id;
    queue * prev;
    queue * next;
};

void init_q(queue *head);
void print_q(queue *q,int len);
void insert_q(pid_t pid, queue *q);
queue *find_q(pid_t p,queue *q,int len);
queue *remove_q(queue *q);
queue *next_q(queue *q);
#endif
