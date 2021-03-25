biblioteca: libro.o main.o
	gcc -g libro.o main.o -o biblioteca

libro.o: libro.c 	
	gcc -g -c libro.c

main.o: libro.h main.c
	gcc -g -c main.c

clean:
	rm *.o	|| true
	rm biblioteca || true
	make	