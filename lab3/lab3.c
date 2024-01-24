#include"lab3.h"
/* only parameter is an int for the size of the array you want allocated
we know this is a char array so we use sizeof(char) for malloc
use an int array to malloc the space for your array using the size parameter
if malloc doesnt work we return 0
the first element is set equal to the size of the array and the array +1 is passed back to user
the user has no idea the size of the array is there, but we can access it using strLEN function
function is char* because we are returning a char * back to the user*/
char * strAlloc(int size)
{  // use int array so you can store the size of the array as the 0th or -1st element
    int * array = malloc((size*sizeof(char)) + sizeof(int)); // allocate enough memory plus size of int for the size of the array to be stored
    if (array == NULL) 
    {
        return 0; // check to make sure malloc worked and returns 0 if it did not work
    } 
    *array = size; // first element set equal to size
    array++;
    return (char*) array; // returns the array as a void pointer +1 so the size is hidden, and you can use any type of pointer since it returns void
}

/* only parameter for this function is the array you want to take the size of
it has to be the same array we allocated the memory for using strAlloc function 
I tried to use casting to make this an integer but I have no idea how*/
int strLen(char *str)
{
    int*array = (int *)str;
    return array[-1];
}
/* the two parameters for this array are a source array and destination array, both typr char*
it is assumed that the dest array is at least as big as the source array
we use the strLen function to find the size of the source array, because it is assumed we used our strAlloc function for this array
then we use a for loop to set each element of the destination array equal to the source array*/
void strCpy(char *source, char *dest)
{
    int size = strLen(source);
    for(int i = 0; i<size; i++)
    {
        dest[i] = source[i];
    }
}
/* i ran out of time but this has the two char array parameters
it is supposed to compare the two strings and return 1 if they are the same and 0 if they arent the same
you have to use %d to find their ASCII values and use a for loop to compare them but I dont have time to finish*/
int strCmp(char *source, char *dest)
{
    int size = strLen(source);

	for(int i = 0; i < size; ++i) {
		if(dest[i] != source[i]) {
			return 0;
		}
	}

	return 1;
    
}
/* this has a parameter char*str that needs to be allocated by strAlloc
it is supposed to free that memory but I can't figure out how to cast it properly*/
void strFree(char *str)
{
    int*array = (int *)str;
    free(array-1);
}
