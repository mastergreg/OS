#
# Makefile
#

CC = gcc
CFLAGS = -Wall -O2

all: mandel pipesem.o

mandel: mandel-lib.o mandel.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o mandel
