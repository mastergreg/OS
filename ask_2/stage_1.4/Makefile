.PHONY: all clean

all: ask2-pipes

CC = gcc
CFLAGS = -g -Wall -O2
SHELL= /bin/bash

ask2-pipes: ask2-pipes.o proc-common.o tree.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY:
	clean

clean: 
	rm -f *.o ask2-pipes{,.o} proc-common.o tree.o
