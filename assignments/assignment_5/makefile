main: main.o item.o list.o utile.o
	gcc -g main.o item.o list.o utile.o -o main
	
item.o: item.c
	gcc -g -c item.c
	
list.o: list.c item.o utile.o
	gcc -g -c list.c
	
main.o: main.c item.o list.o
	gcc -g -c main.c item.o list.o 

utile.o: utile.c
	gcc -g -c utile.c
	 
clean:
	rm -f *.o
	make	