main.exe: main.o item.o list.o
	gcc main.o item.o list.o -o main.exe 
	
item.o: item.c
	gcc -c item.c
	
list.o: list.c item.o
	gcc -c list.c
	
main.o: main.c item.o list.o
	gcc -c main.c item.o list.o -std=c99
	 
clean:
	rm .f *o *.exe