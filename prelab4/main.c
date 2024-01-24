#include"prelab4.h"
int main(void)
{
    FILE * fp;
    fp = NULL;
    Employee * array;
    array = NULL;
    fp = fopen("employees.txt","r");
    array = readEmployeeArray(fp);

    for (int i = 0; i<5; i++)
    {
        printf("empID[%d]: %d,   ",i, array[i].empID);
        printf("jobType[%d]: %d,   ",i, array[i].jobType);
        printf("salary[%d]: %.3f",i, array[i].salary);
        printf("\n");
    }
    Employee * person;
    person = getEmpByID(array, 142342);
    printf("\n");
    printf("here is this employee's numbers\n");
    printf("empID: %d   ", person->empID);
    printf("jobType: %d   ", person->jobType);
    printf("salary: %.3f", person->salary);
    printf("\n");

    float salary;
    int job;
    int ec;
    printf("\n");
    ec = setEmpSalary(array, 1234, 99.99);  
    if (!ec)
    {
    ec = getEmpSalary(array, 1234, &salary);  
    printf("After the function, salary = %.3f\n", salary);
    }
    ec = setEmpJobType(array, 142342, 9876); 
    if (!ec)
    {
    ec = getEmpJobType(array, 142342, &job); 
    printf("After the function, jobType = %d\n", job);
    }

    empFree(array);
    empFree(person);
}