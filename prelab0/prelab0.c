#include <stdio.h>

int ReturnArray(int size, int query, int array[])
{
    int count = 0;
    for (int i = 0; i<size; i++)
    {
        if (array[i]>=query)
        {
            count++;
        }
    }
    return count;
}
int main(void)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int query = 5;
    int size = 10;
    printf("There are %d integers greater than or equal to the query integer\n", ReturnArray(size, query, array)); 
}
