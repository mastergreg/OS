#
# Makefile
#

CC = gcc
CFLAGS = -Wall -O3

all: mandel 

mandel: mandel-lib.o mandel.o pipesem.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<
resize:
	convert mandel.ppm mandel.png

clean:
	rm -f *.o mandel
