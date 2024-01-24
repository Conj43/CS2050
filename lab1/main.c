#include "lab1.h"

int main(void)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    float average = 0;
    int sumOddNum = 0;
    if (getAverage(array, size, &average) == 0)
    {
        printf("The average of this array is: %.3f\n", average);
    }
    if (sumOdd(array, size, &sumOddNum) == 0)
    {
        printf("The sum of odd integers in this array is: %d\n", sumOddNum);
    }
    else printf("There was an error with your array or size variable!\n");

    
    
}