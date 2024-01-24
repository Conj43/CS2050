#include "prelab3.h"

void * createArray(int n, int dataTypeSize)
{
    int *array;  
    array = malloc(n*dataTypeSize + sizeof(int));
    if (array == NULL) return 0;
    array[0] = n; 
    return (void *) (array+1); 
}


int getArraySize(void *array)  // must pass your array as void *
{
    int * p;
    p = array;
    return p[-1];
}


void freeArray(void *array)  // must pass your array as void *
{
    int * p;
    p = array;
    free(p-1);
}