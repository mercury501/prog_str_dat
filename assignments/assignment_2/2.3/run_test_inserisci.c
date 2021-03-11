// file run_test_ins_array.c

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "vettore.h"
# include "utile.h"

# define M 20
# define EXTRA 1    // spazio extra per consentire inserimento


int run_test_case(char *tc_id, int n, int elem, int pos)
{
    // dichiarazione delle variabili necessarie
    char input_fname[M], output_fname[M], oracle_fname[M];	
    int *input_arr, *oracle_arr, *dim;
    dim = xmalloc(sizeof(int));
    *dim = n;

    // costruiamo i nomi dei file
    input_fname[0] = '\0';
    output_fname[0] = '\0';
    oracle_fname[0] = '\0';
    strcat(input_fname, tc_id);
    strcat(input_fname, "_input.txt");
    strcat(output_fname, tc_id);
    strcat(output_fname, "_output.txt");
    strcat(oracle_fname, tc_id);
    strcat(oracle_fname, "_oracle.txt");
    
    // allochiamo memoria per array di input
    // carica file di input
    input_arr = xmalloc(sizeof(int) * (*dim + 1));
    finput_array(input_fname, input_arr, *dim);

    // inserimento in array
    // NB: n � stato incrementato nella funzione inserisci
    inserisci(input_arr, dim, elem, pos);

    // scrive file di outptut
    foutput_array(output_fname, input_arr, *dim);

    // allochiamo memoria per array oracolo
    oracle_arr = xmalloc(sizeof(int) * (*dim));

    // carichiamo oracolo
    finput_array(oracle_fname, oracle_arr, *dim);

    // confrontiamo array
    return confronta_array(input_arr, oracle_arr, *dim);
}	



int main(int argc, char *argv[]) 
{ 	
    FILE *test_suite, *result;    
    char tc_id[M];  // stringa contenente l'identificativo del test case
    int n, pass, element, position;
    
    if(argc < 3){
         printf("Nomi dei file mancanti \n");
         exit(1);
    }    
    

     
    // stringa contenente l'identificativo del test case
    // apro file contenente test suite               
    // apro file contenente risultati test        
    test_suite = fopen(argv[1], "r");  // apro file contenente test suite               
    result = fopen(argv[2], "w");   // apro file contenente risultati test        
    
    if( test_suite==NULL || result == NULL ) {
        printf("Errore in apertura dei file \n");    
        exit(1);
    }
    
    
    
    /* Scansione del file di input nel ciclo while. 
    Ad ogni iterazione si leggono i quattro elementi di una riga:
    l�identificativo del test case tc_id, il numero n di elementi
    da ordinare, l�elemento elem da inserire e la posizione pos  */
    
    while(fscanf(test_suite, "%s%d%d%d", tc_id, &n, &element, &position) == 4){
        pass = run_test_case(tc_id, n, element, position);
    
         fprintf(result,"%s ", tc_id);
         if(pass == 1)
               fprintf(result, "PASS \n");
         else   
               fprintf(result, "FAIL \n");			
        }	
    
    
    
    // chiusura file di input
    // chiusura file di output
    fclose(test_suite);  // chiusura file di input
    fclose(result);         // chiusura file di output
}

