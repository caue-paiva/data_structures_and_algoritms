all: skip_list_tad2.o item.o
	gcc -o skip_list_app skip_list_tad2.o item.o

skip_list_tad2.o: skip_list_tad2.c
	gcc -c skip_list_tad2.c

item.o: item.c	
	gcc -c item.c

clean:
	rm *.o *.exe