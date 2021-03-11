run_test_somma_array:  utile.o vettore.o  run_test_somma_array.o
	gcc   utile.o vettore.o  run_test_somma_array.o  -o run_test_somma_array


utile.o:		utile.c
	gcc -c utile.c

vettore.o:	vettore.c  
	gcc -c vettore.c

run_test_somma_array.o: 	vettore.h   run_test_somma_array.c	
	 gcc -c run_test_somma_array.c
	
clean:	
	rm *.o
	make
