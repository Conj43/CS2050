#include"prelab1.h"
void getArrayInfo(int array[], int size, int *minval, int *maxval)
{   
    int min, max;  // I used code from the slides for this function
    min = max = array[0];
    for (int i=1; i<size; i++) 
    {
        if (array[i] < min)   min = array[i];
        if (array[i] > max)   max = array[i];
    }
    *minval = min;   
    *maxval = max;
    
    int count = 0;
    int distinct = 0;
    int temp = 0;
    int i = 0;
    for (i = 0; i<size; i++)
    {
        temp = array[i];
        for (int p = i; p<size; p++)
        {
            if (temp == array[p+1])
            {
                count++;
                break;
            }
        }
    }
    distinct = size-count;
    printf("There are %d distinct numbers in this array!\n", distinct);
}