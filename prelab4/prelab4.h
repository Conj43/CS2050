#include<stdio.h>
#include<stdlib.h>

typedef struct { 
     int empID, jobType; 
     float salary; 
} Employee; 
Employee * readEmployeeArray(FILE *fp);
Employee * getEmpByID(Employee * person, int empID);  
void empFree(Employee * array);
int empLen(Employee *array);
Employee * empAlloc(int size, int datatype);
int setEmpSalary(Employee *, int empID, float salary);  
int getEmpSalary(Employee *, int empID, float *salary);  
int setEmpJobType(Employee *, int empID, int job); 
int getEmpJobType(Employee *, int empID, int *job); 
