
#include <stdio.h>
#include <stdlib.h>

#define N 100
/* creo una serie di funzioni che possono essermi utili, come xmalloc che controlla che la malloc sia andata a buon fine, 
e la mia versione homebrew di strcpy, strncpy e strlen */

void *xmalloc(size_t nbytes){   

    void *result;

    result = malloc(nbytes);

    if (!result){
        fprintf(stderr, "xmalloc(%lu) failed, BYE\n", nbytes);
        exit(-1);
    }

    return result;

}

void mycpy(char dst[], char src[]){
    int i = 0;
    do{
        dst[i] = src[i];
        i++;

    } while (src[i] != '\0');

    
}

void myncpy(char dst[], char src[], int n){
    int i;
    for (i = 0; i < n; i++)
        dst[i] = src[i];
    
    dst[i] = '\0';

}

int mylen(char buff[]){
    int i;
    for (i = 0; buff[i] != '\0'; i++)   {}

    return i;
}

/* creo una funzione che legge da tastiera una stringa e la alloca dinamicamente */
char *leggi_alloca_str(){ 
    char buff[100];
    

    scanf ("%s", &buff);

    char *temp_p = xmalloc ((mylen(buff) + 1) * sizeof(char));
    
    mycpy(temp_p, buff);

    return temp_p;

}

/* ed un'altra che stampa l'array di char a video, che è terminato da NULL come una stringa */
void print_char_array(char buff[]){
    int i;
    for (i = 0; buff [i] != '\0'; i++)
        printf("%c", buff[i]);
}


/* funzione che trova la lettera con valore minimo, tenendo il minimo corrente in una variabile e cambiandolo all'occorrenza in un ciclo */
char minimo(char *t){
    int i, index = 0, len = mylen(t);

    for (i = 1; i < len; i++)
        if (t[i] < t[index])
            index = i;

    return t[index];

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

    temp = xmalloc((sizeof(char) * mylen(buff)) + 1);
    mycpy(temp, buff);

    return temp;
}


/* funzione incastona, che discerne la stringa più grande, calcola l'offset dove inserire la più piccola, e crea un unovo buffer così composto */

char *incastona(char *str1, char *str2){

    char *little, *big, *final;
    int ltl_len, big_len;
    char buff[N];
    int start_pos, i, j;

    if (mylen(str1) > mylen(str2)){   //controlliamo qual è la stringa piccola e quale grande
        big = str1;
        little = str2;
    }
    else{
        big = str2;
        little = str1;
    }

    ltl_len = mylen(little);
    big_len = mylen(big);
    start_pos = (big_len - (big_len / 2)) - (ltl_len - (ltl_len / 2));
   

    for (i = 0; i <= big_len; i ++){
        if (i < start_pos || i >= (start_pos + ltl_len))    //prima e dopo la stringa piccola, copiamo la grande
            buff[i] = big[i];
        else if ( i = start_pos){   //copiamo interamente la stringa piccola
            for (j = 0; j < ltl_len; j++)
                buff[i + j] = little[j];
            i += ltl_len - 1;   //aggiorniamo il valore di i per essere alla fine dell'array popolato
        }

    }


    final = xmalloc((mylen(buff) * sizeof(char)) + 1);
    myncpy(final, buff, mylen(big));

    return final;
    
}

/* ordina l'array con bubble sort, come fosse un array di int */

char *ordina( char* str){
    char buff[N], temp, *final;
    mycpy (buff, str);

    int i,j, len_str = mylen(str);

    for(i = 0; i < len_str - 1; i++)    
        for (j = 0; j < len_str - 1; j++)
            if (buff[j] > buff[j + 1]){
                temp = buff[j];
                buff[j] = buff[j + 1];
                buff[j + 1] = temp; 
            }

    final = xmalloc((mylen(buff) * sizeof(char)) + 1);
    myncpy(final, buff, len_str);

    return final;

}

int main(void){
    char *nome, *cognome, *concat, *incast, *n_ord, *c_ord;

    printf("Inserire nome:  ");
    nome = leggi_alloca_str();
    printf("\nInserire cognome:  ");
    cognome = leggi_alloca_str();

    concat = merge(nome, cognome);

    incast = incastona(nome, cognome);

    n_ord = ordina(nome);
    c_ord = ordina(cognome);


    printf("\nConcatenazione:  ");
    print_char_array(concat);

    printf("\nMinimo del nome:  %c\nMinimo del cognome:  %c\n", minimo(nome), minimo(cognome));

    printf("\nIncastonato:   ");
    print_char_array(incast);

    
    printf("\nNome ordinato:  ");
    print_char_array(n_ord);

    printf("\nCognome ordinato:  ");
    print_char_array(c_ord);


    printf("\n\n");
    return 0;

}