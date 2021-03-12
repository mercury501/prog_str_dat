run_test_somma_array:  utile.o vettore.o  run_test_somma_array.o
	gcc   -g utile.o vettore.o  run_test_somma_array.o  -o run_test_somma_array


utile.o:		utile.c
	gcc -g -c utile.c

vettore.o:	vettore.c  
	gcc -g -c vettore.c

run_test_somma_array.o: 	vettore.h   run_test_somma_array.c	
	 gcc -g -c run_test_somma_array.c
	
clean:	
	rm *.o
	make
