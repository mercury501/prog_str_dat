#include <stdlib.h>
#include <stdbool.h>
#include "item.h"
#include "utile.h"

typedef struct node *list;


list newList(void);
int emptyList(list l);
list tailList(list l);
list consList(item val, list l);
item getFirst (list l);
int sizeList(list l);

int posItem(list l, item val);
item getItem (list l, int pos);

list reverseList (list l);

void outputList (list l);
list inputList (int n);

list insertList(list l, int pos, item val);
list removeList(list l, int pos);