all: main.o lista.o item.o
	gcc main.o lista.o item.o -o main -std=c99 -Wall -lm

run: main.o
	./main

main.o: main.c
	gcc -c main.c

lista.o: lista.c
	gcc -c lista.c

item.o: item.c	
	gcc -c item.c

clean:
	del -f *.o *.exe