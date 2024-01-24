#include"prelab2.h"
/* this function is passed a file pointer, the file has to already be opened
then it is also passed in the address of the size of the array because it doesn't know the length of the 
array until it reads the file
the function will first put the first value in the file equal to the size, because that is the size
then it will use malloc to create an array of that size
then it checks if malloc worked, and returns 0 if not
then it uses a while loop to read the values from the file and place them into the array in consecutive order
then the file is closed and the function returns the float array*/
float * readFloatFileIntoArray(FILE *fptr, int *length)  
{
    
    int first, size;
    float number;
    if (1 == fscanf(fptr, "%d", &first))
    {
        size = first;
    }
    *length = size;
    float * array = malloc(sizeof(float)*size);
    if (array == NULL)
    {
        return 0;
    }
    int i = 0;
    while (1==fscanf(fptr,"%f", &number))
    {
        array[i] = number;
        i++;
    }
    fclose(fptr);
    return array;
}
/* this function is passed in a ** pointer, because you are passing in the address of a pointer
this function the uses free the free the space allocated by malloc in the previous function
then the pointer is set to null and there is no return because this is passed by reference and it is a void function*/
void freeFloatArray(float ** ptr)
{
    free(*ptr);
    *ptr = NULL;
}



