all: skip_list_string.o item.o
	gcc -o skip_list_app skip_list_string.o item.o

skip_list_string.o: skip_list_string.c
	gcc -c skip_list_string.c

item.o: item.c	
	gcc -c item.c

clean:
	del *.o *.exe