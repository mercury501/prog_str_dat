#include "stack.h"

struct c_stack {
     list top;
};

stack newStack(void)
{
     stack s;
     s = xmalloc (sizeof(struct c_stack));

     s->top = newList();
     return s;
}

int emptyStack(stack s)
{
     return emptyList(s->top);
}

int push(item val, stack s)
{  
    return insertList(s->top, 0, val);
}

int pop (stack s)
{   
   return removeList(s->top, 0);
}

item top (stack s)
{
    return getFirst(s->top);
}

stack cloneStack(stack s){

     stack new = newStack();
     new->top = cloneList(s->top);

     return new;

}

int sizeStack(stack s){

     return sizeList(s->top);

}

stack invertStack(stack s){
     stack temp = cloneStack(s);

     temp->top = reverseList(temp->top);

     return temp;
}

void print_stack(stack s){
     stack temp = cloneStack(s);
     int i = 0;

     while (emptyStack(temp) != 1){
          printf("Elemento n. %d:  ");
          output_item(top(temp));
          printf("\n");
          pop(temp);
          i++;
     }

     free(temp);
}

stack mergeStack(stack st, stack st1){

     int i, dim = sizeStack(st);

     stack merged = cloneStack(st1);
     stack clone = cloneStack(st);
     clone = invertStack(clone);

     for (i = 0; i < dim; i++){
          push(top(clone), merged);
          pop(clone);
     }    

     free(clone);

     return merged;
}