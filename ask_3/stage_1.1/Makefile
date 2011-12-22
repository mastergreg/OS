#
# Makefile
#

CC = gcc
CFLAGS = -Wall -O2

all: pipesem.o pipesem-test

pipesem-test: pipesem.o proc-common.o pipesem-test.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<





#proc-common.o: proc-common.h proc-common.h
	$(CC) $(CFLAGS) -c -o proc-common.o proc-common.c

#pipesem.o: pipesem.c pipesem.h
	$(CC) $(CFLAGS) -c -o pipesem.o pipesem.c

## Pipesem
#pipesem-test.o: pipesem.h pipesem-test.c
	$(CC) $(CFLAGS) -c -o pipesem-test.o pipesem-test.c

#pipesem-test: pipesem.o pipesem-test.o
	$(CC) $(CFLAGS) -o pipesem-test pipesem.o pipesem-test.o

clean:
	rm -f *.o pipesem-test

