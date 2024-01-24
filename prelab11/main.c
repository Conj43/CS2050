#include "prelab11.h"

int main(void)
{
    Employee e1 = {10};
    Employee e2 = {5};
    Employee e3 = {15};
    Employee e4 = {20};
    Employee e5 = {30};
    Employee e6 = {25};
    Employee e7 = {70};
    Employee e8 = {90};
    Employee e9 = {40};
    Employee e10 = {55};
    Employee e11= {60};
    Employee e12 = {65};
    Employee * arr[] = {&e1, &e2, &e3, &e4, &e5, &e6, &e7, &e8, &e9, &e10, &e11, &e12};
    int size = 12;


    EmpDatabase p = createSearchableEmployeeDB();
    for(int i = 0; i<size; i++)
    {
        p = insertEmp(arr[i], p);
    }
    printTree(p);
    int count = countEmpsInSalaryRange(30, 60, p);
    printf("There are %d salaries in the range 30 to 60\n", count);
    freeEmpDatabase(p);
}