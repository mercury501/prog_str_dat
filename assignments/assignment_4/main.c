#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"

#define BUFFSIZE 100


//Ricerca del libro pi� vecchio
libro libropiuvecchio(libro* biblioteca){
  int i, an, index = 0; //inizializziamo l'indice del libro più vecchio al primo
  an = anno(biblioteca[0]); //e l'anno più vecchio al primo

  for (i = 1; biblioteca[i] != NULL; i++)
    if (anno(biblioteca[i]) < an){  //scorriamo l'array, aggiornando anno e indice
      an = anno(biblioteca[i]);
      index = i;
    }

  return biblioteca[index]; //restituiamo il libro, qui come puntatore dato che so che non verrà modificato da altro, altrimenti ne avrei allocata un'altra copia

}

//Ricerca del libro meno costoso
libro libromenocostoso(libro* biblioteca){
  int i, pr, index = 0; //inizializziamo l'indice del libro meno costoso al primo
  pr = prezzo(biblioteca[0]); //inizializziamo il prezzo meno costoso al primo libro

  for (i = 1; biblioteca[i] != NULL; i++)
    if (prezzo(biblioteca[i]) < pr){  //scorriamo l'array, e aggiorniamo prezzo e indice in caso di prezzo minore
      pr = prezzo(biblioteca[i]);
      index = i;
    }

  return biblioteca[index]; //restituiamo il libro 
}

//Trova tutti i libri dell�editore X
libro* ricercaeditore(libro* biblioteca, char* edit){
  libro* scaffale;
  int index_size = dimensione_lista_libri(biblioteca);  //controllo la dimensione di biblioteca per allocare lo spazio necessario a indexes
  int indexes[index_size], dim = 0, i;
  
  for (i = 0; biblioteca[i] != NULL; i++)
    if (strcmp(editore(biblioteca[i]), edit) == 0){ //mi salvo in un array le posizioni dei libri di un certo autore
      
      dim++;
      indexes[dim - 1] = i;
    }
  
  scaffale = malloc(sizeof(libro) * dim); //alloco uno scaffale grande quanto basta

  for(i = 0; i < dim; i++)  //e lo riempio coi libri presi dall'array indexes
    scaffale[i] = creaLibro(titolo(biblioteca[indexes[i]]), editore(biblioteca[indexes[i]]), prezzo(biblioteca[indexes[i]]), anno(biblioteca[indexes[i]]));

  return scaffale;  //e lo restituisco
}

//Ridurre del X% il costo dei libri dell�anno AAAA.
// questa funzione potrebbe restituire void oppure un intero
// che restiuisce 0 in caso tutto � andato correttamente
void scontalibri(libro* biblioteca, int an, float percentuale){

    int i;
    for (i = 0; biblioteca[i] != NULL; i++) //se i libri sono di un determinato anno, li passo alla funzione sconto
      if (anno(biblioteca[i]) == an)
        sconto(biblioteca[i], percentuale);

}

//Trova due libri con scarto di prezzo minore
//la teoria è: compilo un array con la differenza di prezzo tra se stesso e tutti gli altri libri, e così via per tutti gli altri libri, alla fine trovo il minimo nella 
//matrice, e i suoi indici mi diranno quali sono i libri con scarto minore
libro* trovalibriprezzosimile(libro* biblioteca){
  int dim = dimensione_lista_libri(biblioteca);
  float comparison[dim][dim], minimo = 10000;
  int i, j, min_index_x, min_index_y;
  libro *scaffale;
  scaffale = malloc(sizeof(libro *) * 2);

  for(i = 0; i < dim; i++)
    for (j = 0; j < dim; j++){
            
      comparison[i][j] = prezzo(biblioteca[i]) - prezzo(biblioteca[j]); //popolo la matrice con le differenze di prezzo, controllando che non siano negative
      
      if (comparison[i][j] < 0)
        comparison[i][j] *= -1;
    }

  
  for(i = 0; i < dim; i++)
    for (j = 0; j < dim; j++)
      if (comparison[i][j] < minimo && i != j){ //trovo il minimo della matrice, salvandomi i suoi indici
        minimo = comparison[i][j];
        min_index_x = i;
        min_index_y = j;
      }
        
  scaffale[0] = biblioteca[min_index_x];  //salvo i libri corrispondenti agli indici del minimo, e restituisco lo scaffale
  scaffale[1] = biblioteca[min_index_y];

  return scaffale;

}

//Calcola il costo totale di tutti i libri dell�anno AAAA
float costototale(libro* biblioteca, int an){
  float temp = 0;
  int i;
  for (i = 0; biblioteca[i] != NULL; i++) //sommo alla variabile temp il prezzo di tutti i libri, e la restituisco
    if (anno(biblioteca[i]) == an)
      temp += prezzo(biblioteca[i]);

    return temp;
}

//Elimina i libri dell'anno AAAA
void eliminaLibri(libro* biblioteca, int an){
  libro temp;
  int i, j, bib_dim;
  bib_dim = dimensione_lista_libri(biblioteca);

  for (i = 0; i < bib_dim; i++)
    if (anno(biblioteca[i]) == an){ //se trovo un libro dell'anno in esame, lo dealloco e shifto l'intero array a sinistra
      free(biblioteca[i]);
      for (j = i; j < bib_dim - 1; j++)
        biblioteca[j] = biblioteca[j + 1];
      
      biblioteca[bib_dim - 1] = NULL; //annullo l'ultimo puntatore altrimenti l'ultimo e penultimo elemento punteranno allo stesso libro

      bib_dim --;
    }

}







int main(int argc, char *argv[])
{

  int n=0;
  libro *biblioteca, *scaffale;
  libro temp_libro;
  char tit[100]="";
  char ed[50]="";
  char buffer[50];
  float pr;
  int an, choice, perc;
  FILE *fp;


  
  if (argc == 1){
  printf("Inserire il numero di libri in biblioteca da inserire:  ");
  scanf("%d", &n);
  }
  else if (argc == 2){
    printf("Usage: biblioteca file_libri.txt NUMERO_LIBRI\n");
    exit(1);
  }
  else
  {
    
    fp = fopen(argv[1], "r");

    if (fp == NULL){
        fprintf(stderr, "\ncant open file\n");
        exit(1);
    }

    n = atoi(argv[2]);
  }

  biblioteca = malloc(sizeof(libro)*n);

  for (int i=0; i<n; i++){
    if (argc == 1){
    printf("\nInserire il titolo, seguito da editore, prezzo e anno\n");
    fgets(tit, 100, stdin);
    fgets(ed, 50, stdin);
    scanf("%f", &pr);
    scanf("%d", &an);
    }

    else {
      fgets(tit, 100, fp);  //leggo gli elementi del libro da file
      fgets(ed, 50, fp);
      fscanf(fp, "%d\n%f\n", &an, &pr);

    }
    
    biblioteca[i] = creaLibro(tit, ed, pr, an);
  
  }

  //realizzare le varie funzioni dell'esercizio
  printf("Inserire operazione da effettuare:\n1 libro più vecchio\n2 libro meno costoso\n3 ricerca editore\n4 sconta libri\n5 trova libri di prezzo simile\n6 il costo totale dei libri\n7 elimina un libro\n8 stampa biblioteca\n");
  scanf("%d", &choice);

  switch(choice){
    case 1:
    temp_libro = libropiuvecchio(biblioteca);
    printf("Il libro più vecchio è %sedito da %sdel %d, e costa %f euro\n", titolo(temp_libro), editore(temp_libro), anno(temp_libro), prezzo(temp_libro));
    break;

    case 2:
    temp_libro = libromenocostoso(biblioteca);
    printf("Il libro meno costoso è %sedito da %sdel %d, e costa %f euro\n", titolo(temp_libro), editore(temp_libro), anno(temp_libro), prezzo(temp_libro));
    break;

    case 3:
    printf("Inserire autore da cercare:  ");
    fgets(ed, 50, stdin); //per togliere la newline rimasta dall'ultima gets
    fgets(ed, 50, stdin);
    scaffale = ricercaeditore(biblioteca, ed);
    stampa_lista_libri(scaffale);
    break;

    case 4:
      printf("Inserire l'anno dei libri da scontare: ");
      scanf("\n%d", &an);
      printf("\nInserire la percentuale di sconto:  ");
      scanf("%d", &perc);
      scontalibri(biblioteca, an, pr);
      stampa_lista_libri(biblioteca);
      break;
    
    case 5:
      scaffale = trovalibriprezzosimile(biblioteca);
      printf("I libri di prezzo simile sono:\n");
      stampa_lista_libri(scaffale);
      break;


    case 6:
      printf("Inserire l'anno dei libri da considerare: ");
      scanf("%d", &an);
      printf("\nIl costo totale dei libri è di:  %f euro.\n", costototale(biblioteca, an));
      break;
    
    case 7:
      printf("Inserire anno dei libri da eliminare:  ");
      scanf("%d", &an);
      eliminaLibri(biblioteca, an);
      stampa_lista_libri(biblioteca);
      break;

    case 8:
      printf("Lista libri: \n");
      stampa_lista_libri(biblioteca);
      break;

    default:
      printf("scelta non contemplata\n");
      return 1;
  }
  
	
  return 0;
}
