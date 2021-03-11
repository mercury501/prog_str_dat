// FILE:   vettore.c
// restituisce 1 se i due vettori di ingresso sono uguali, 0 altrimenti

#include "vettore.h"
#define M 20

int confronta_array(int a[], int b[], int n) 
{  
	int i;

	for (i = 0; i < n; i++)
		if (a[i] != b[i])
			return 0;
	
	return 1;
}

void foutput_array(char *file_name, int a[], int n) 
{  
	int i;  
	FILE *fd; 	

    //aprire il file in scrittura
    fd = fopen(file_name, "w");

    //controllare che il file sia stato aperto correttamente
	if (fd == NULL){
	fprintf(stderr, "cant open file in foutput\n");
	fprintf(stderr, "%s\n", file_name);
	exit(1);
}
	//e scrivere il contenuto (fprintf()) di a in fd
	for (i = 0; i < n; i ++)
		fprintf(fd, "%d\n", a[i]);
	
	// chiudere il file
	fclose(fd);
}

void finput_array(char *file_name, int a[], int n)
{
	int i;
	FILE *fd;
	char buff[M];

    //apertura file in lettura
	fd = fopen(file_name, "r");

	//Controllare se il file esiste 
	if (fd == NULL){
        fprintf(stderr, "cant open file in finput\n");
		fprintf(stderr, "%s\n", file_name);
        exit(1);
    }
	
		
	//leggere il contenuto (fscanf()) da scrivere in array a
	for (i = 0; i < n; i ++){
		if(feof(fd))
			break;

		fscanf(fd, "%s\n", buff);
		a[i] = atoi(buff);

	}
		
	//chiudere il file
	fclose(fd);
}

void ordina(int a[], int n) {
	int i,j;
	
	for(i = 0; i < n - 1; i++)    
		for (j = 0; j < n - 1; j++)
			if (a[j] > a[j + 1])
				scambia(&a[j], &a[j + 1]);   

}
