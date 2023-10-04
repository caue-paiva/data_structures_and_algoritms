all: inverte_lista.o lista.o item.o
	gcc -o lista_inverter  inverte_lista.o lista.o item.o

run: all 
	./lista_inverter

inverte_lista.o: inverte_lista.c
	gcc -c inverte_lista.c

lista.o: lista.c
	gcc -c lista.c

item.o: item.c	
	gcc -c item.c

clean:
	del *.o *.exe