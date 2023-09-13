all: item.o pilha.o main.o
	gcc item.o pilha.o main.o -o dfs -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

pilha.o:
	gcc -c pilha.c -o pilha.o

main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o dfs

run:
	./dfs