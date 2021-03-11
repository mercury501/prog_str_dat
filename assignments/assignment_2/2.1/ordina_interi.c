
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100


void *xmalloc(size_t nbytes){   

    void *result;

    result = malloc(nbytes);

    if (!result){
        fprintf(stderr, "xmalloc(%lu) failed, BYE\n", nbytes);
        exit(-1);
    }

    return result;

}


void ordina( int* a, int n){    //ordinamento con bubble sort
    int temp;
    int i,j;

    for(i = 0; i < n - 1; i++)    
        for (j = 0; j < n - 1; j++)
            if (a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp; 
            }
    return;

}





int main(int argc, char *argv[]){
    
    if (argc <= 2){ //se il programma è stato chiamato senza parametri
    printf("Usage: ordina_interi NUM1 NUM2 [...]\n");
    exit(0);
    }
    int i, a[N];
    int dim = argc - 1;

    for (i = 0; i < dim; i++)
        a[i] = atoi(argv[i + 1]);



    ordina(a, dim);

    for (i = 0; i < dim; i ++)
        printf("%d, ", a[i]);

    printf("\n\n");

    return 0;

}