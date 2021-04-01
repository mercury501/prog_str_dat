#include "item.h"

struct miolibro{
    char titolo[100];
    char editore[50];
    float prezzo;
    int anno;      
	   
};

int eq(item x, item y) {
      if ((strcmp(x.titolo, y.titolo)) &&
            (strcmp(x.editore, y.editore)) &&
            (x.prezzo == y.prezzo) &&
            (x.anno == y.anno))
            return 1;

      return 0;
}

void input_item(item *x) {
     //scanf("%d", x);
} 

void output_item(item x) {
      //printf("%d", x);
} 
