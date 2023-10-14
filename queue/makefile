all: queues1.o teste.o
	gcc -o queues.exe queues1.o teste.o

teste.o: teste.c queues1.o
	gcc -c teste.c 

queues1.o: queues1.c
	gcc -c queues1.c

clean:
	rm *.o *.out