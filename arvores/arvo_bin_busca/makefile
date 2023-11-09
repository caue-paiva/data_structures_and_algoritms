all: abb.o item.o main.o
	gcc -o abb.out abb.o item.o main.o 

item.o: item.c
	gcc -c item.c

abb.o: abb.c item.o
	gcc -c abb.c

main.o: main.c item.o abb.o
	gcc -c main.c

clean:
	rm *.out *.o 