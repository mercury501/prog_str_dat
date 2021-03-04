#include <stdio.h>

#define N 100

int insert_el(int a[], int dim, int el, int index){
    int i;

    if (index > dim)    //indice fuori array, esci
        return 1;

    for (i = dim - 1; i >= index; i--)  //a ritroso, l'ultimo elemento diventa il penultimo etc etc
        a[i] = a[i - 1]; 

    a [index] = el;

    return 0;

}

int elimin_el(int a[], int dim, int index){
    int i;

    if (index > dim)
        return -1;

    for (i = index; i < dim - 1; i ++)
        a[i] = a[i + 1];


    return dim - 1;

}

int trova_minimo(int a[], int dim){
    int i, temp_min = a[0];

    for (i = 1; i < dim; i++)
        if (a[i] < temp_min)
            temp_min = a[i];


    return temp_min;
}

int trova_el(int a[], int dim, int el){
    int i, index = -1;

    for (i = 0; i < dim; i++)
        if (a[i] == el)
            return i;

    return 1;
}

int trova_el_bin(int a[], int dim, int el){
    int i, index, mid = (dim - 1) / 2;  //mid point, trasforma la dimensione in un indice e lo divide per 2

    if (el == a[mid])   //se l'elemento è nel mezzo, restituisci l'indice
        return mid;
    
    if (a[mid - 1] > el)
        return trova_el(a, mid, el);
    else
        return trova_el(&a + mid + 1, mid, el); //TODO

}

void print_arr(int a[], int dim){
    int i;

    for (i = 0; i < dim; i++)
        printf("%d, ", a[i]);

}

int main(void){

    int arr[N] = {1,2,3,4,5,6,7,8};

    insert_el(arr, 8, arr[7], 2);

    print_arr(arr, 8);

    elimin_el(arr, 8, 1);

    print_arr(arr, 7);

    printf("ELEMENTO IN  %d", trova_el_bin(arr, 7, 6));


    return 0;



}