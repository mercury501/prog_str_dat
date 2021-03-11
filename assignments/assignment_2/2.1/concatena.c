
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



/* funzione che concatena, copia la prima stringa nel buffer, e poi copia la seconda partendo dall'ultima posizione della prima */

char *merge(char *str1, char *str2){
    char buff[N], *temp;
    int i, j;
    for (i = 0; str1[i] != '\0'; i++)
        buff[i] = str1[i];

    for (j = i; str2[j - i] != '\0'; j++)
        buff[j] = str2[j - i];            
    buff[j] = '\0';

    temp = xmalloc((sizeof(char) * strlen(buff)) + 1);
    strcpy(temp, buff);

    return temp;
}


char * alloca_str(char buff[]){ //funzione che legge una stringa dai parametri ricevuti all'avvio
    char *temp = xmalloc((sizeof(char) * strlen(buff)) + 1);
    strcpy(temp, buff);
    return temp;
}




int main(int argc, char *argv[]){
    char *str1, *str2, *concat;

    if (argc <= 2){ //se il programma è stato chiamato senza parametri
        printf("Usage: concatena STRINGA1 STRINGA2\n");
        exit(0);
    }

    
    str1 = alloca_str(argv[1]);
    
    str2 = alloca_str(argv[2]);

    concat = merge(str1, str2);

    printf("\n%s\n\n", concat);
    return 0;

}