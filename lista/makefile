all: lista_encad.o num_grandes.o
	gcc -lm -o num_grandes.exe lista_encad.o num_grandes.o

lista_encad.o: lista_encad.c
	gcc -c lista_encad.c

num_grandes.o: num_grandes.c
	gcc -lm -c num_grandes.c
clean:	
	del -f *.o num_grandes.exe
