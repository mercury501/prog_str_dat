main: punto.o main.o
	gcc -g punto.o main.o -o main
	
punto.o: punto.c
	gcc -g -c punto.c
	
main.o: main.c punto.h
	gcc -g -c main.c 

	
clean:
	rm main
	rm *.o
	make