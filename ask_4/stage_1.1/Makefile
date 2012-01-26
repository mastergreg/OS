#
# Makefile
#
# Operating Systems, Exercise 4
#

CC = gcc
CFLAGS = -Wall -g
#CFLAGS = -Wall -O2 -g

all: scheduler prog execve-example strace-test

scheduler: scheduler.o proc-common.o queue.o
	$(CC) -o scheduler queue.o scheduler.o proc-common.o
prog: prog.o proc-common.o
	$(CC) -o prog prog.o proc-common.o

execve-example: execve-example.o
	$(CC) -o execve-example execve-example.o

strace-test: strace-test.o
	$(CC) -o strace-test strace-test.o

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
#proc-common.o: proc-common.c proc-common.h
#	$(CC) $(CFLAGS) -o proc-common.o -c proc-common.c
#
#scheduler.o: scheduler.c proc-common.h request.h
#	$(CC) $(CFLAGS) -o scheduler.o -c scheduler.c
#
#prog.o: prog.c
#	$(CC) $(CFLAGS) -o prog.o -c prog.c
#
#execve-example.o: execve-example.c
#	$(CC) $(CFLAGS) -o execve-example.o -c execve-example.c
#
#strace-test.o: strace-test.c
#	$(CC) $(CFLAGS) -o strace-test.o -c strace-test.c

clean:
	rm -f scheduler prog execve-example strace-test *.o
