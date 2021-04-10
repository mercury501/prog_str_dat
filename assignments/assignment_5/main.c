#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

void finput_array(char *file_name, list a)
{
	int i, dim, temp;
	FILE *fd;

	fd=fopen(file_name, "r");
	if( fd==NULL )
		printf("Errore in apertura del file %s \n", file_name);
	else {
        fscanf(fd, "%d", &dim);
		for(i=0; i<dim; i++){
			fscanf(fd, "%d", &temp);
            consList(temp, a);
        }
		fclose(fd);
		}
}


int main (int argc, char *argv[]){
    
    FILE *fp;
    int i, n, temp;
    list num_list = newList();
    
    finput_array("numbers.txt", num_list);

    outputList(num_list);

    printf("L'elemento 25, se esiste, è in posizione: %d\n", posItem(num_list, 25));
    printf("L'elemento 55, se esiste, è in posizione: %d\n", posItem(num_list, 55));

    num_list = reverseList(num_list);
    outputList(num_list);

    return 0;
}
