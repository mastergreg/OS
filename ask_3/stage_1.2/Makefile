#
# Makefile
#

CC = gcc
CFLAGS = -Wall -O2

all: mandel pipesem.o

proc-common.o: proc-common.h proc-common.h
	$(CC) $(CFLAGS) -c -o proc-common.o proc-common.c

pipesem.o: pipesem.c pipesem.h
	$(CC) $(CFLAGS) -c -o pipesem.o pipesem.c

## Mandel
mandel-lib.o: mandel-lib.h mandel-lib.c
	$(CC) $(CFLAGS) -c -o mandel-lib.o mandel-lib.c

mandel.o: mandel-lib.h mandel.c
	$(CC) $(CFLAGS) -c -o mandel.o mandel.c

mandel: mandel-lib.o mandel.o
	$(CC) $(CFLAGS) -o mandel mandel-lib.o mandel.o

clean:
	rm -f *.o mandel
