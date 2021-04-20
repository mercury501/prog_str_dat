#include <stdio.h>
#include "utile.h"
#include "stack.h"
#include "item.h"


int main(void){
    item value = 0;
    stack st = newStack();

    printf("Riempire lo stack, terminato da un -1:\n");
    
    while (1){
        scanf("%d", &value);
        if (value == -1)
            break;
        
        push(value, st);

    }

    print_stack(st);

    stack st1 = invertStack(st);
    
    printf("\nStack invertito:\n");
    print_stack(st1);               

    printf("\nStack uniti: \n");
    stack merged = mergeStack(st, st1);
    print_stack(merged);

    return 0;




}
