// Connor Joyce Lab 1 CS2050 SP23 Semester
#include "lab1.h"
int getAverage(int array[], int size, float *result) // finds the average of an array of ints
{
    if (size > 0) // check to make sure the array is not a negative size, and is not 0 in size
    {
        if (sizeof(array[0]) == sizeof(int)) //checks to make sure array contents are type int
        {  
        int sum = 0;  //this variable is used to calculate the total sum of the array
        for (int i = 0; i<size; i++) // this for loop adds up all the values in the array and puts them into sum
        {
            sum = array[i]+sum;
        }
        *result = sum/size;  // this is using pass by reference to store the average in result
        return 0;
    }
    }
    else return 1;  // this is returning one because the size variable that was passed in was not greater than 0, or the function couldn't calculate the average because it wasn't type int
}


int sumOdd(int array[], int size, int *result) // finds sum of odd ints in an array of ints
{
    if (size > 0) //// check to make sure the array is not a negative size, and is not 0 in size
    {
        if (sizeof(array[0]) == sizeof(int)) //checks to make sure array contents are type int
        {   
        int sum = 0; // ill use this to find the sum of the odd numbers
        for(int i = 0; i<size; i++)
        {
            if (array[i]%2 != 0)    // this checks if the number is divisible by 2, and if it isn't then it adds that number to the sum
            {
            sum = array[i] + sum;
            }
        }
        *result = sum;  // this uses pass by reference to store the sum of add numbers into this pointer
        return 0;
        }
    }
    else return 1;  // this is returning one because the size variable that was passed in was not greater than 0, or the function couldn't calculate the sum of odd numbers because it wasn't type int
}

// note: i thought about putting if sum = 0 then return error, but theere could be negative numbers and positive numbers that cause it to be negative or 0