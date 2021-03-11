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

int check_vocal(char letter){

    switch(letter){
        case 'a': return 1;
        case 'e': return 1;
        case 'i': return 1;
        case 'o': return 1;
        case 'u': return 1;

        default:return 0;
    }

}


char **vocali_consonanti(char* str){    //la funzione restituisce un array di stringhe di dimensione 2, la prima contiene le vocali e la seconda le consonanti

    char **voc_cons = xmalloc(sizeof(char*) * 2);
    char cbuff[N], vbuff[N];
    int cdim = 0, vdim = 0, i, len = strlen(str);

    for (i = 0; i < len; i++)
        if (check_vocal(str[i]) == 1){
            vbuff[vdim] = str[i];
            vdim ++;
        }
        else{
            cbuff[cdim] = str[i];
            cdim ++;
        }


    voc_cons[0] = xmalloc((sizeof(char) * vdim) + 1);
    voc_cons[1] = xmalloc((sizeof(char) * cdim) + 1);

    strncpy(voc_cons[0], vbuff, vdim);
    strncpy(voc_cons[1], cbuff, cdim);

    return voc_cons;


}

char * alloca_str(char buff[]){ //funzione che legge una stringa dai parametri ricevuti all'avvio
    char *temp = xmalloc((sizeof(char) * strlen(buff)) + 1);
    strcpy(temp, buff);
    return temp;
}


int main(int argc, char *argv[]){

    if (argc < 2){ //se il programma è stato chiamato senza parametri
        printf("Usage: vocali_consonanti STRINGA\n");
        exit(0);
    }

    char *test = alloca_str(argv[1]);   //allochiamo dinamicamente la stringa da testare, si potrebbe anche passare direttamente argv[1]

    char **result = vocali_consonanti(test);

    printf("%s\n%s\n", result[0], result[1]);


    return 0;

}