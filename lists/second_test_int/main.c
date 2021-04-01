#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void){
    int i;
    char tit[100];
    char ed[50];
    int an;
    float pr;
    FILE *fp;

    fp = open_file_read("libri.txt");

    for (i = 0; i < 10; i++){
        fgets(tit, 100, fp);  //leggo gli elementi del libro da file
        fgets(ed, 50, fp);
        fscanf(fp, "%d\n%f\n", &an, &pr);
    
    
    }
    list new = newList();
    new = consList(25, new);
    new = consList(42, new);
    //outputList(new);

    reverseList(new);

    outputList(new);    

    return 0;
}