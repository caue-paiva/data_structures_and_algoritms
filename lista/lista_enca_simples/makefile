all: lista.o item.o
	gcc -o lista_inverter.exe lista.o item.o

run: lista_inverter.exe
	lista_inverter.exe	

lista.o: lista.c
	gcc -c lista.c

item.o: item.c	
	gcc -c item.c

clean:
	del *.o *.exe