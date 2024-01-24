#include"prelab4.h"

Employee * empAlloc(int size, int datasize)
{  
    int * array = malloc(((size*datasize)) + sizeof(int)); // allocate enough memory plus size of int for the size of the array to be stored
    if (array == NULL) 
    {
        return 0; // check to make sure malloc worked and returns 0 if it did not work
    } 
    *array = size; // first element set equal to size
    array++;
    return (Employee*) array; // returns the array as a  pointer +1 so the size is hidden, and you can use any type of pointer since it returns void
}
int empLen(Employee *array)
{
    int*p = (int *)array;
    return p[-1];
}
Employee * readEmployeeArray(FILE *fp)
{
    Employee * array;
    int first, size, empID, jobType;
    float salary;
    if (1 == fscanf(fp, "%d", &first))
    {
        size = first;
    }
    array = empAlloc(size, sizeof(Employee));
    int i = 0;
    while (3==fscanf(fp,"%d, %d, %f", &empID, &jobType, &salary))
    {
        array[i].empID = empID;
        array[i].jobType = jobType;
        array[i].salary = salary;
        i++;
    }
    fclose(fp);
    return array;
}

Employee * getEmpByID(Employee * array, int empID)
{
    Employee * bruh = empAlloc(1, sizeof(Employee));
    int size = empLen(array);
    for(int i = 0; i<size; i++)
    {
        if (array[i].empID == empID)
        {
            *bruh= array[i];
        }
    }
    if (!bruh)
    {
        return 0;
    }
    return bruh;
}
void empFree(Employee * array)
{
    int*p = (int *)array;
    free(p-1);
}

int setEmpSalary(Employee * array, int empID, float salary)
{
    int size = empLen(array);
    int count = 0;
    for(int i = 0; i<size; i++)
    {
        if (array[i].empID == empID)
        {
            array[i].salary = salary;
            count++;
        }
    }
    if (count == 1) return 0;
    else return 1;

}

int getEmpSalary(Employee * array, int empID, float *salary)
{
    int size = empLen(array);
    int count = 0;
    for(int i = 0; i<size; i++)
    {
        if (array[i].empID == empID)
        {
            *salary = array[i].salary;
            count++;
        }
    }
    if (count == 1) return 0;
    else return 1;
} 

int setEmpJobType(Employee * array, int empID, int job)
{
    int size = empLen(array);
    int count = 0;
    for(int i = 0; i<size; i++)
    {
        if (array[i].empID == empID)
        {
            array[i].jobType = job;
            count++;
        }
    }
    if (count == 1) return 0;
    else return 1;
} 

int getEmpJobType(Employee * array, int empID, int *job)
{
    int size = empLen(array);
    int count = 0;
    for(int i = 0; i<size; i++)
    {
        if (array[i].empID == empID)
        {
            *job = array[i].jobType;
            count++;
        }
    }
    if (count == 1) return 0;
    else return 1;
}