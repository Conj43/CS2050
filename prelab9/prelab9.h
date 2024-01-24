#include<stdio.h>
#include<stdlib.h>

typedef struct empStruct{
    int ID, SSN;
}Employee;

typedef struct database{
    Employee * ssnSort[250];
    Employee * idSort[250];
    int size, ec;
}EmpDatabase;

EmpDatabase createSearchableEmployeeDB(Employee ** p, int size);
Employee * findEmpBySSN(int SSN, EmpDatabase p);
Employee * findEmpByID(int ID, EmpDatabase p);
void freeEmpDatabase(EmpDatabase p);
int getErrorCode(EmpDatabase p);