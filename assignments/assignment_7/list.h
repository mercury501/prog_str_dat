#include <stdlib.h>
#include <stdbool.h>
#include "item.h"
#include "utile.h"

typedef struct c_list *list;


list newList(void);
int emptyList(list l);
list tailList(list l);      //da rivedere
list consList(item val, list l);

item getFirst (list l);
int sizeList(list l);

int posItem(list l, item val);
item getItem (list l, int pos);

int insertList(list l, int pos, item val);
int removeList (list l, int pos);

list reverseList (list l);  //da testare
list cloneList(list l);

void outputList (list l);
list inputList (int n);

