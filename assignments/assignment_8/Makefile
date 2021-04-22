main: main.o item.o utile.o queue.o
	gcc -g main.o item.o utile.o queue.o -o main -lm

main.o: main.c item.o queue.o
	gcc -g -c -lm main.c item.o  queue.o

queue.o: item.o  utile.o
	gcc -g -c queue.c item.o utile.o

item.o: item.c utile.o
	gcc -g -c -lm item.c utile.c
	
utile.o: utile.c
	gcc -g -c utile.c
	 
clean:
	rm -f *.o
	rm -f main
	make	