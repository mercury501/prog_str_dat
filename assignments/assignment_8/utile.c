#include "utile.h"

FILE *open_file_read(char *filename){

    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL){
        fprintf(stderr, "\nCannot open file %s\n", filename);
        exit(1);
    }

    return fp;
}

void *xmalloc(size_t nbytes){

    void *result;

    result = malloc(nbytes);

    if (!result){
        fprintf(stderr, "xmalloc(%lu) failed, BYE\n", nbytes);
        exit(-1);
    }

    return result;
}