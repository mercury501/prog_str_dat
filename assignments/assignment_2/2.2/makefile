run_test_ordina_array:	utile.o  vettore.o  run_test_ordina_array.o
	gcc -g utile.o  vettore.o  run_test_ordina_array.o  -o run_test_ordina_array

utile.o:		utile.c
	gcc -g -c utile.c

vettore.o:	vettore.c  utile.h
	gcc -g -c vettore.c

run_test_ordina_array.o: 	vettore.h   run_test_ordina_array.c	
	 gcc -g -c run_test_ordina_array.c
	
clean:	
	rm *.o
	make