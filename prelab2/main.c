#include "prelab2.h"

int main(void)
{
    FILE * fp;
    fp = NULL;
    int size = 0;
    float * array;
    array = NULL;
    fp = fopen("numbers.txt","r");
    array = readFloatFileIntoArray(fp, &size);
    for (int i = 0; i<size; i++)
    {
        printf("Array[%d] = %.6f\n",i,  array[i]);
    }
    freeFloatArray(&array);
    

}