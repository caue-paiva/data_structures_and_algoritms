all: avl.o conjunto.o main_projeto.o item.o
	gcc -o main_projeto  avl.o conjunto.o main_projeto.o item.o

avl.o: avl.c item.o
	gcc -c avl.c

conjunto.o: conjunto.c avl.o item.o
	gcc -c conjunto.c

main_projeto.o: main_projeto.c avl.o item.o
	gcc -c main_projeto.c

item.o: item.c
	gcc -c item.c

clean_lin:
	rm -f *.o main_projeto

clean_win:
	del *.exe *.o 
