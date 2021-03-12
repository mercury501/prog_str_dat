run_test_inserisci:  vettore.o  run_test_inserisci.o utile.o
	gcc   -g utile.o vettore.o  run_test_inserisci.o  -o run_test_inserisci

utile.o:		utile.c
	gcc -g -c utile.c

vettore.o:	vettore.c  
	gcc -g -c vettore.c

run_test_inserisci.o: 	vettore.h   run_test_inserisci.c	
	 gcc -g -c run_test_inserisci.c
	
clean:	
	rm *.o
	make