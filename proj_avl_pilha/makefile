all: avl.o conjunto.o main_projeto.o item.o stack_linkada.o
	gcc -g -o main_projeto avl.o conjunto.o main_projeto.o item.o  stack_linkada.o

avl.o: avl.c avl.h item.h stack_linkada.o
	gcc -g -c  avl.c

stack_linkada.o: item.o stack_linkada.c
	gcc -g -c stack_linkada.c


conjunto.o: conjunto.c conjunto.h avl.h item.h avl.o
	gcc -g -c  conjunto.c

main_projeto.o: main_projeto.c avl.h item.h conjunto.h stack_linkada.o avl.o
	gcc -g -c  main_projeto.c

item.o: item.c item.h
	gcc -g -c  item.c


clean_lin:
	rm -f *.o main_projeto

clean_win:
	del *.exe *.o
