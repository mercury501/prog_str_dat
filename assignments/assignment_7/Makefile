main: main.o item.o list.o utile.o stack.o
	gcc -g main.o item.o list.o utile.o stack.o -o main

main.o: main.c item.o list.o stack.o
	gcc -g -c main.c item.o list.o stack.o

stack.o: item.o list.o utile.o
	gcc -g -c stack.c item.o list.o utile.o

item.o: item.c
	gcc -g -c item.c
	
list.o: list.c item.o utile.o
	gcc -g -c list.c
	
utile.o: utile.c
	gcc -g -c utile.c
	 
clean:
	rm -f *.o
	rm -f main
	make	