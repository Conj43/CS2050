#include <stdio.h>
#include<stdlib.h>

typedef struct BST{
    int salary;
    struct BST * left;
    struct BST * right;
}Employee;

typedef struct database{
    Employee * head;
    int ec, size;
}EmpDatabase;

EmpDatabase createSearchableEmployeeDB(); // Just inits your struct
EmpDatabase insertEmp(Employee * emp, EmpDatabase p);
int countEmpsInSalaryRange(int min, int max, EmpDatabase p);
void freeEmpDatabase(EmpDatabase p);
int getErrorCode(EmpDatabase p);
void printTree(EmpDatabase p);
