#
# Makefile
#

CC = gcc
CFLAGS = -Wall -O2

all: procs-shm pipesem.o

proc-common.o: proc-common.h proc-common.h
	$(CC) $(CFLAGS) -c -o proc-common.o proc-common.c

pipesem.o: pipesem.c pipesem.h
	$(CC) $(CFLAGS) -c -o pipesem.o pipesem.c

## Procs-shm
procs-shm.o: proc-common.h procs-shm.c
	$(CC) $(CFLAGS) -c -o procs-shm.o procs-shm.c

procs-shm: proc-common.o procs-shm.o
	$(CC) $(CFLAGS) -o procs-shm proc-common.o procs-shm.o

clean:
	rm -f *.o procs-shm
