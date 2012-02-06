#
# Makefile
#
# Operating Systems, Exercise 4
#

CC = gcc
CFLAGS = -Wall -Wextra -Wuninitialized -g
#CFLAGS = -Wall -O2 -g

all: scheduler-shell prog execve-example strace-test shell

scheduler-shell: scheduler-shell.o proc-common.o queue.o
	$(CC) -o scheduler-shell queue.o scheduler-shell.o proc-common.o
prog: prog.o proc-common.o
	$(CC) -o prog prog.o proc-common.o

execve-example: execve-example.o
	$(CC) -o execve-example execve-example.o

strace-test: strace-test.o
	$(CC) -o strace-test strace-test.o

shell: shell.o

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -f scheduler-shell shell prog execve-example strace-test *.o
