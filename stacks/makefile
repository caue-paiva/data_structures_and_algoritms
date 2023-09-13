all: stacks
stacks: stack_as_single_array.o stack.o
	gcc stack_as_single_array.o stack.o -o stacks

stacks_as_single_array.o: stack_as_single_array.c stack.h
	gcc -c stack_as_single_array.c

stack.o: stack.c stack.h
	gcc -c stack.c  

gene: stack_gene.o stack_gene.h
	gcc  stack_gene.c  -o gene.out   

clean:
	rm *.o *.exe  *.out
