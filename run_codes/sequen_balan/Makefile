all: item.o Pilha.o main.o balanceada.o
	gcc item.o Pilha.o main.o balanceada.o -o balanceada -std=c99 -Wall

item.o: item.c item.h
	gcc -c item.c -o item.o

Pilha.o: Pilha.c Pilha.h
	gcc -c Pilha.c -o Pilha.o

balanceada.o: balanceada.c
	gcc -c balanceada.c -o balanceada.o

main.o: main.c
	gcc -c main.c -o main.o

clean:
	del *.o *.exe

run:
	./balanceada
