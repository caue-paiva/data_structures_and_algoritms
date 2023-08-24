all: stacks
stacks: stack_as_single_array.o stack.o
	gcc stack_as_single_array.o stack.o -o stacks

stacks_as_single_array.o: stack_as_single_array.c stack.h
	gcc -c stack_as_single_array.c

stack.o: stack.c stack.h
	gcc -c stack.c       

clean:
	rm -f stack_as_single_array.o stack.o stacks
