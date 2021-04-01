#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void){

    list new = newList();
    new = consList(25, new);
    new = consList(42, new);
    outputList(new);

    return 0;
}