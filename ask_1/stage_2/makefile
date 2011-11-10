all: 		fconc
fconc:		fconc.o
	gcc fconc.o -o fconc
fconc.o: 	fconc.c fconc.h
	gcc -c fconc.c -o fconc.o -Wall
clean:
	rm fconc.o fconc C
