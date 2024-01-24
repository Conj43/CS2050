#include "prelab3.h"

int main(void)
{
    int size = 20;
    char * array;
    array = createArray(size, sizeof(char));
    array = ("HelloHelloHelloHello");
    
    for (int i = 0; i<size; i++)
    {
        printf("Array[%d] = %c\n",i, array[i]);
    }
    printf("The size of your array is %d!\n", getArraySize((void*)array));
    freeArray((void*)array);
}