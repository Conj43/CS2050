#include"lab4.h"

/* makeArray: this function uses malloc to create an int array using the parameters to find the size
plus space of one integer which will be the size stored in front of the array
if the array == NULL after using malloc, the function returns 0 because that means malloc didnt work
then the first element of the array is set equal to the size of the array which was passed in through the parameter arraySize
and the array is indexed forwards by one so the size is hidden before the array before it is passed back to the user
the return value is a void pointer that has the given space for the array and can be set equal to a pointer

parameters: an integer that is for the arraySize which will be stored at the first index of the array
elementSize which is the size of each element in the array and the two parameters will be multiplied in malloc to determine how
much space malloc uses
note: the elementSize should be passed in using the sizeof() operator in main so that the function is given the integer
value of the size of that type*/
void * makeArray(int arraySize, int elementSize)
{
    int * array = malloc(((arraySize*elementSize)) + sizeof(int)); // allocate enough memory plus size of int for the size of the array to be stored
    if (array == NULL) 
    {
        return 0; // check to make sure malloc worked and returns 0 if it did not work
    } 
    *array = arraySize; // first element set equal to size
    array++; //index array by one to hide size
    return (void *) array; //return a void pointer that can be set equal to any type of pointer
}

/* getSize: a simple function that allows the user to pass in anytype of pointer as long as it was created by makeArray
it returns the value of the size of the array which is stored in front of thr array
since that value is an int and we initialized the array as int* we use int*p and set that equal to the array
that is passed in. then we return the -1st element, which is where we stored the size using makeArray

parameter: just a void* that can be any type of pointer as long as it was created by makeArray
it is cast as an int* in the function so it can be set equal to that type and we return the -1st element*/
int getSize(void *array)
{
    int*p = (int *)array; //use casting to set equal to int*
    return p[-1];  // return p[-1] which is the size of the array
}

/* countwithColors: first uses getSize function to get the size of the array that was passed in to the function
it is necessary that said array was created using makeArray
then uses a loop to find when the given colorcount occurs in the struct
use count variable to count how many times we find a color that is equal to the colorcount
we then return count back to the user

parameters: first is an array of type InventoryItem and it needs to be created using makeArray because we use getSize in this function
then the user passer in colorCount which is just whatever number they are looking for in the color part of the struct
we return to them the number that colorCounr occured */
int countWithColors(InventoryItem *items, short colorCount)
{
    int size = getSize(items); // use getSize so we can know how many times to loop
    int count = 0; // use this variable to count how many times colorCount == items[i].colors
    for(int i = 0; i<size; i++)
    {
        if(colorCount == items[i].colors)
        {
            count++; //increases by one everytime colorCount == items[i].colors
        }
    }
    return count; // return count back to the user
}

/* freeArray: this function frees an array that was created by makeArray
it uses a similar function as getSize to cast the array back to an int then frees p-1 because in makeArray
we returned array+1, so when we free it we need to free it just as how we got it when we malloc-ed it
parameter: just an array that was made by makeArray
it is type void and it casted as an int in the function so it can be any type
*/
void freeArray(void *array)
{
    int*p = (int *)array; //cast it back as an int* because that was what it malloc-ed as
    free(p-1); //free -1 because we did ++ in makeArray
}