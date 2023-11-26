all: avl.o conjunto.o main2.o item.o
	gcc -o main2.exe  avl.o conjunto.o main2.o item.o

avl.o: avl.c item.o
	gcc -c avl.c

conjunto.o: conjunto.c avl.o item.o
	gcc -c conjunto.c

main2.o: main2.c avl.o item.o
	gcc -c main2.c

item.o: item.c
	gcc -c item.c

clean:
	del *.exe *.o 