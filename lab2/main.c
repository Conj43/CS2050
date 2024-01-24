#include"lab2.h"
int main(void)
{
    int  initialize[5] = {2, 4, 0, 6, 0};
    /*int * array = NULL;
    array = initialize;
    makeArray(&array, 10);
    int count = 0;
    for (int i = 0; i<10; i++)
    {
        array[i] = count;
        count++;
    }
    for (int i = 0; i<10; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
    freeArray(&array);
    */
    /*initArray(initialize, 5);
    for (int i = 0; i<5; i++)
    {
        printf("element %d = %d\n", i, initialize[i]);
    }
    */
    printf("there are %d odd integers in your array\n", multiplyOdd(initialize, 5, 3));
    for (int i = 0; i<5; i++)
    {
        printf("element %d = %d\n", i, initialize[i]);
    }
    


}
