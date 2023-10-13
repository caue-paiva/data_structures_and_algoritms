all: principal.o skip_list_string.o item.o
	gcc -o skip_list_ex principal.o skip_list_string.o item.o

principal.o: skip_list_string.o item.o
	gcc -c principal.c

skip_list_string.o: skip_list_string.c
	gcc -c skip_list_string.c

item.o: item.c	
	gcc -c item.c

clean:
	del *.o *.exe