all: princi.o matrizes.o
	gcc -o princi.exe princi.o matrizes.o

princi.o: princi.c
	gcc -c princi.c

matrizes.o: matrizes.c
	gcc -c matrizes.c

clean:
	def -f *.o *.exe