// file run_test_ins_array.c

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "vettore.h"
# include "utile.h"

#define M 20



int run_test_case(char *tc_id, int n)
{  
    char input0_fname[M], input1_fname[M], output_fname[M], oracle_fname[M];	
    int *input0_arr, *input1_arr, *oracle_arr, *output_arr;

    // costruiamo i nomi dei file
    input0_fname[0] = '\0';
    input1_fname[0] = '\0';
    output_fname[0] = '\0';
    oracle_fname[0] = '\0';

    strcat(input0_fname, tc_id);
    strcat(input0_fname, "_input1.txt");
    strcat(input1_fname, tc_id);
    strcat(input1_fname, "_input2.txt");
    strcat(output_fname, tc_id);
    strcat(output_fname, "_output.txt");
    strcat(oracle_fname, tc_id);
    strcat(oracle_fname, "_oracle.txt");

    //printf("%s\n%s\n%s\n", input_fname, output_fname, oracle_fname);
    // allochiamo memoria per array di input
    input0_arr = xmalloc(sizeof(int) * n);
    input1_arr = xmalloc(sizeof(int) * n);
    output_arr = xmalloc(sizeof(int) * n);

    // carica file di input
    finput_array(input0_fname, input0_arr, n);
    finput_array(input1_fname, input1_arr, n);

    // ordina array
    somma_array(input0_arr, input1_arr, output_arr, n);

    //  scrive file di output
    foutput_array(output_fname, output_arr, n);
 
    // allochiamo memoria per array oracolo
    oracle_arr = xmalloc(sizeof(int) * n);

    // carichiamo oracolo
    finput_array(oracle_fname, oracle_arr, n);

    // confrontiamo array e facciamo return
    return confronta_array(output_arr, oracle_arr, n);	
}	



int main(int argc, char *argv[]) 
{ 	
    FILE *test_suite, *result;  
    char tc_id[M];  // stringa contenente l'identificativo del test case
    int n, pass;
    
    if(argc < 3){
         printf("Nomi dei file mancanti \n");
         exit(1);
    }    
    
    test_suite = fopen(argv[1], "r");  // apro file contenente test suite               
    result = fopen(argv[2], "w");   // apro file contenente risultati test        
    
    if( test_suite==NULL || result == NULL ) {
        printf("Errore in apertura dei file \n");    
        exit(1);
    }

    while(fscanf(test_suite, "%s%d", tc_id, &n) == 2){
         pass = run_test_case(tc_id, n);
    
         fprintf(result,"%s ", tc_id);
         if(pass == 1)
               fprintf(result, "PASS \n");
         else   
               fprintf(result, "FAIL \n");			
        }	
    
    fclose(test_suite);  // chiusura file di input
    fclose(result);         // chiusura file di output


}

