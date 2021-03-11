// Implementazione del Modulo: file utile.c
#include "utile.h"
/* commenti relativi alla progettazione 
e realizzazione della funzione scambia */

void scambia(int * x, int * y)
{	

    int temp = *x;
    *x = *y;
    *y = temp;
    
}



void *xmalloc(size_t nbytes){

    void *result;

    result = malloc(nbytes);

    if (!result){
        fprintf(stderr, "xmalloc(%lu) failed, BYE\n", nbytes);
        exit(-1);
    }

    return result;

}