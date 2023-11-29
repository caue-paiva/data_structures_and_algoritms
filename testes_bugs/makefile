all: main_teste.o stack_linkada.o item.o
	gcc -o mainteste main_teste.o stack_linkada.o item.o

item.o: item.c item.h
	gcc -c -Wall item.c

stack_linkada.o: stack_linkada.c stack_linkada.h item.o
	gcc -c -Wall stack_linkada.c


main_teste.o: main_teste.c stack_linkada.o item.o
	gcc -c -Wall main_teste.c




clean_lin:
	rm -f *.o mainteste