#include <stdio.h>
#include <string.h>
#define NULLITEM 0

typedef struct miolibro item;

int eq(item x, item y);
void input_item(item *x); 
void output_item(item x);
