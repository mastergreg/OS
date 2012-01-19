/*
 * monitorsem.c
 *
 * References from
 * A. Silberschatz, P. Galvin, and G. Gangne. Operating System Concept. John Wiley & Sons
 * 
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>

/* The functions are intentionally left blank :-) */
/* the function names are left the same for compatibility */

#include "monitorsem.h"

Monitor 
void pipesem_init(struct pipesem *sem, int val)
{
	freeBlock = n;
	nextIn = 0;
	nextOut = 0;
}

void pipesem_wait(struct pipesem *sem)
{
    if(freeBlock == n) //Nothing to read
	reader.wait;
	item a = buffer[nextOut];
	freeBlock++;
	nextOut = (nextOut + 1) % n;
	writer.signal;
	return item;
}

void pipesem_signal(struct pipesem *sem)
{
    
}

void pipesem_destroy(struct pipesem *sem)
{
    
}
