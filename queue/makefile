all: queues1.o carcs.o
	gcc -o queues.out queues1.o carcs.o

carcs.o: carcs.c queues1.o
	gcc -c carcs.c 

queues1.o: queues1.c
	gcc -c queues1.c

clean:
	rm *.o *.out