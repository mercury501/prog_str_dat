run_test_inserisci:  vettore.o  run_test_inserisci.o utile.o
	gcc   utile.o vettore.o  run_test_inserisci.o  -o run_test_inserisci

utile.o:		utile.c
	gcc -c utile.c

vettore.o:	vettore.c  
	gcc -c vettore.c

run_test_inserisci.o: 	vettore.h   run_test_inserisci.c	
	 gcc -c run_test_inserisci.c
	
clean:	
	rm *.o
	make