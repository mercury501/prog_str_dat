run_test_ordina_array:	utile.o  vettore.o  run_test_ordina_array.o
	gcc utile.o  vettore.o  run_test_ordina_array.o  -o run_test_ordina_array

utile.o:		utile.c
	gcc -c utile.c

vettore.o:	vettore.c  utile.h
	gcc -c vettore.c

run_test_ordina_array.o: 	vettore.h   run_test_ordina_array.c	
	 gcc -c run_test_ordina_array.c
	
clean:	
	rm *.o
	make