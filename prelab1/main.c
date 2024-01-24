#include"prelab1.h"
int main(void)
{
    int array[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    int  min = 0;
    int  max = 0;
    int size = 9;
    getArrayInfo(array, size, &min, &max);
    printf("The minimum value is: %d\n", min);
    printf("The maximum value is: %d\n", max);
}