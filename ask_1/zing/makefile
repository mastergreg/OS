all:	main
main:   main.o
	gcc main.o zing.o -o main -Wall -m32
main.o: main.c
	gcc -c main.c -o main.o -Wall -m32
clean:
	rm main.o main
