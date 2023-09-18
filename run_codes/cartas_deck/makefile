all: cartas.o fila.o item.o
	gcc -o cartas.out cartas.o fila.o item.o

cartas.o: cartas.c fila.o item.o
	gcc -c cartas.c

fila.o: fila.c  item.o
	gcc -c fila.c

item.o: item.c
	gcc -c item.c

clean:
	rm -rf *.o *.out