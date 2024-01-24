#include "lab9.h"
/*I added this function, and I use it so I can use recursion in my searchClients function
it uses mid, left and right values to determine what the index is of the client struct we are searching for
it also has paramaters to pass in the array and the client struct we are looking for
it uses a simple binary search recursion algorithm to loop through until it returns the value of the index of the
query client
if none of the things are true it will return -1 indicating an error to the user
I also assumed the array is sorted in increasing order by aaccount number because it is not specified in the lab document*/
int binarySearch(int left, int mid, int right, Client * query, Client * array)
{
    mid = left + (right - left) / 2; //determines middle each time it recurses through
    if (left ==right)
    {
      return -1;  
    }
    else{
    if (query->accountWorth == array[mid].accountWorth) {
            return mid; //if we find the index, then return that index
        } else if (query->accountWorth < array[mid].accountWorth) {
            right = mid; // if query is greater than current mid, move the right so we only look at values less than mid now
            return binarySearch(left, mid, right, query, array);
        } else if (query->accountWorth > array[mid].accountWorth){
            left = mid + 1; // if query is less than current mid it only looks at values greater than mid and returns this back to the function
            return binarySearch(left, mid, right, query, array);
        }
    }
    
        return -1;
}
/* this function has parameters of array size and element soze, so user will need to use sizeof() to pass in their element size
it uses the logic from the beginning of this class to store the array size at the beginning of the array
we used an int * to be able to do this*/
void * makeArray(int arraySize, int elementSize)
{
    int * array = malloc(((arraySize*elementSize)) + sizeof(int)); // allocate enough memory plus size of int for the size of the array to be stored
    if (array == NULL) 
    {
        return NULL; // check to make sure malloc worked and returns NULL if it did not work
    } 
    *array = arraySize; // first element set equal to size
    array++; //index array by one to hide size
    return (void *) array; //return a void pointer that can be set equal to any type of pointer
}
/* simple function that cna only be used by an array that was made by makeArray because it just looks at the -1st 
element because that is where the value of the size is stored*/
int getSize(void *array)
{
    int*p = (int *)array; //use casting to set equal to int*
    return p[-1];  // return p[-1] which is the size of the array
}

// O(log(n))
/* this uses binary search alogirthm to find a query client struct in an array of client structs
it is assumed the array is sorted in increasing order by account number
I used the binary search function in order to implement this using recursion
since this uses binary search, it has a complexity of O(log(n))
it returns the index of the query client on success (which will be positive)
or it returns -1 on failure which indicates an error*/
int searchClients(Client *array, Client *query)
{
    {
    int size = getSize(array);
    int left = 0;
    int right = size - 1; // account for the fact indexing starts at 0
    int mid = left + (right - left) / 2; // set value of mid which is basically just size/2
    int index = -1; //initialize to -1 so we know if there is an error
    index = binarySearch(left, mid, right, query, array); // this is the recursive function
    return index; // -1 on error, index of query on success
}
}

// O(1)
/* this function just has two parameters which are pointers to Client structs
all we do here is compare the two accountWorths
since accountWorth is in our Client struct this is easy and is done in O(1) time because
we are given the actual structs by the user
returns 0 if a == b , -1 if a < b and 1 if a > b
returns -2 if there is an error*/
int compareClients(Client *a, Client *b)
{
    if (a->accountWorth > b->accountWorth)
    {
        return 1;
    }
    if (a->accountWorth < b->accountWorth)
    {
        return -1;
    }
    if (a->accountWorth == b->accountWorth)
    {
        return 0;
    }
    return -2;// just to indicate an error occured

}
/* this function just takes an array that was made by makeArray
has to be made by makeArray because we need to also free the memeory that was allocated to store the size of the array
which is in front of the array
we can simply free it by casting it back as an int* and freeing p-1 which will free the whole array including the size
in front of the array*/
void freeArray(void *array)
{
    int * p = (int*)array;
    free(p-1);
}