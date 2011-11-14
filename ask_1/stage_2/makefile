all: 		fconc
fconc:		fconc.o
	gcc fconc.o -o fconc
fconc.o: 	fconc.c fconc.h
	gcc -c fconc.c -o fconc.o -Wall
.PHONY: clean test
clean:
	rm fconc.o fconc C
test:
	./fconc A B C D E F
strace:
	strace -o strace_outfile ./fconc A B C D E F
	
