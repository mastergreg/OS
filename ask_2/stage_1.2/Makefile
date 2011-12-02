.PHONY: all clean

all: ask2-tree

CC = gcc
CFLAGS = -g -Wall -O2
SHELL= /bin/bash

ask2-tree: ask2-tree.o proc-common.o tree.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY:
	clean

clean: 
	rm -f *.o ask2-tree{,.o} proc-common.o
