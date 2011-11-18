all: 		fconc
fconc:		fconc.o
	gcc fconc.o -o fconc -m32
fconc.o: 	fconc.c fconc.h
	gcc -c fconc.c -o fconc.o -Wall -m32
.PHONY: clean test strace
clean:
	rm fconc.o fconc C
test:
	./fconc A B C
strace:
	strace -o strace_outfile ./fconc A B C

