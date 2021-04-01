test_list: main.o list.o utile.o item.o
	gcc -g main.o list.o utile.o item.o -o test_list

main.o: main.c utile.h list.h
	gcc -g -c main.c

list.o: list.c utile.h item.h
	gcc -g -c list.c

utile.o:  utile.c 
	gcc -g -c utile.c

item.o: item.c 
	gcc -g -c item.c

clean:
	rm *.o	|| true
	rm test_list || true
	make	