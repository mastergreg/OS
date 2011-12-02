.PHONY: all clean

all: ask2-fork

CC = gcc
CFLAGS = -g -Wall -O2
SHELL= /bin/bash

ask2-fork: ask2-fork.o proc-common.o tree.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY:
	clean

clean: 
	rm -f *.o ask2-fork{,.o} proc-common.o
