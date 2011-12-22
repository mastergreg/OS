#
# Makefile
#

CC = gcc
CFLAGS = -Wall -O2

all: mandel procs-shm pipesem.o pipesem-test

proc-common.o: proc-common.h proc-common.h
	$(CC) $(CFLAGS) -c -o proc-common.o proc-common.c

pipesem.o: pipesem.c pipesem.h
	$(CC) $(CFLAGS) -c -o pipesem.o pipesem.c

## Bonus
rand-fork.o:
	$(CC) $(CFLAGS) -c -o rand-fork.o rand-fork.c
rand-fork:
	$(CC) $(CFLAGS) -o rand-fork pipesem.o rand-fork.o


clean:
	rm -f *.o rand-fork
