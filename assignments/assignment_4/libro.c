
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"

struct miolibro{
    char titolo[100];
    char editore[50];
    float prezzo;
    int anno;      
	   
};

libro creaLibro(char *t, char* e, float p, int a){
      libro temp;
      temp = malloc(sizeof(struct miolibro));
      strcpy(temp->titolo, t);
      strcpy(temp->editore, e);
      temp->prezzo = p;
      temp->anno = a;

      return temp;      
}

char* titolo(libro l)
{
     return l->titolo;
	 
}

char* editore(libro l)
{
      return l->editore;
	  
}

int anno(libro l)
{
      return l->anno;
}

float prezzo(libro l)
{
    return l->prezzo;
}

float sconto(libro l, float percentuale)
{
    l->prezzo = (l->prezzo / 100) * (100 - percentuale);
    return l->prezzo;
}

void aggiorna (libro l, int anno){
	l->anno = anno;
	
}

void stampa_lista_libri(libro *scaffale){
    int i;
    if (scaffale[0] == NULL)
        printf("Lista libri vuota\n");
    else
        for (i = 0; scaffale[i] != NULL; i++)
            printf("Libro n. %d, titolo %sedito da %sdel %d, e costa %f euro\n", (i+ 1),  titolo(scaffale[i]), editore(scaffale[i]), anno(scaffale[i]), prezzo(scaffale[i]));

}

int dimensione_lista_libri(libro *scaffale){
    int i;

    for (i = 0; scaffale[i] != NULL; i++)   ;
       

    return i;
}