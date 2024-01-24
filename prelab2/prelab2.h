#include<stdio.h>
#include<stdlib.h>

float * readFloatFileIntoArray(FILE *fptr, int *length); 
void freeFloatArray(float ** ptr);