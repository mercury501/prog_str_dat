#include <stdio.h>
#include <stdlib.h>

#include "item.h" 
#include "list.h"
#include "utile.h"

typedef struct c_stack *stack;


stack newStack();
int emptyStack();
int push(item val, stack s);
int pop(stack s);
item top(stack s);
stack cloneStack(stack s);
stack invertStack(stack s);
void print_stack(stack s);
stack mergeStack(stack st, stack st1);
int sizeStack(stack s);