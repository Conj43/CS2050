#include "lab2.h"
/* in the function makeArray there are two parameters, a pointer to an int pointer and the size of the new int array
that you'd like to make
the purpose of this function is to make a new array using a pointer that has already been used
it returns one if malloc fails (is equal to NULL) and returns 0 if the memory was properly allocated
we have to use ** because the pointer needs to be passed in by reference using the & symbol*/
int makeArray(int **array, int size)
{
    *array = malloc((size)*sizeof(int)); // have to dereference the array variable so the address of the array is set to the pointer
    if (*(array) == NULL) 
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* this function initalizes every element in an integer array to 0
the parameters are an integer pointer/array, and the size of the array
since this is a void function, there is no return value necessary
when the function is run in the main.c or wherever it is, as long as the correct parameters are passed then the
array will be changed and the user will have an array with each index set to 0
*/
void initArray(int *array, int size)
{
    for (int i = 0; i<size; i++)  //the for loop uses the size passed in to know when to stop setting equal to 0
    {
        array[i]= 0;   // for each index, the value is set equal to zero
    }
}


/* this function counts the number of odd integers (not including 0) and returns that value back to the user
this function also multiplies every odd integer by a multiplicand, which is determined by the user and passed in the third parameter
the parameters are an integer array, the size of the array and the multiplicand
*/
int multiplyOdd(int *array, int size, int multiplicand)
{
    int count = 0;  //this variable will increase by 1 everytime there is an odd integer found
    for (int i = 0; i<size; i++) // the loop goes through each index in the array
    {
        if ((array[i] % 2) != 0)  // this means iff array[i] is not divisible by two, then execute the following code
        {                                       // if the integer is divisible by two, this code is skipped over and it goes to the next index in the array
            array[i] = array[i]*multiplicand;   // this changes the value of the odd numbers in the array, and once this function is executed the values are changed
            count++; // everytime the if statement is true, count increases by one
        }
    }
    return count;  // the user is returned the value of the number of odd integers in the array
}


/* this functions parameter is a pointer to an int pointer, it will be used to free the memory allocated in the 
makeArray function
it is passed using ** because the user needs to pass in the address of the pointer using the & symbol
we then use the free function to free the memory that we took 
you have to dereference it because we are using pass by reference in this
the same thing with setting it to NULL, it is pass by reference and it just sets the pointer equal to NULL so that we 
don't mess anything up*/
void freeArray(int **array)
{
    free(*array);
    *array = NULL;
}