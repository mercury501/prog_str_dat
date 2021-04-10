#ifndef ITEM_H
#define ITEM_H
typedef struct puntoitem *item;
#endif

#define NULLITEM 0

int eq(item x, item y);

//NOTA. il prototipo della funzione di input differisce da 
//      void input_item(item *it)
//      si può anche scegliere di implementare quella funzione
//      ATTENZIONE: allocare opportunamente lo spazio di memoria
item input_item(); 

void output_item(item x);
float distanza(item p1, item p2);
