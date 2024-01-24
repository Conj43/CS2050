#include"prelab9.h"

int main(void) {
    // Sample employees
    Employee e1 = {123, 111111111};
    Employee e2 = {456, 222222222};
    Employee e3 = {789, 333333333};
    Employee e4 = {1, 1114321};
    Employee e5 = {4, 25234222};
    Employee e6 = {7, 332433};
    Employee e7 = {2, 1121241};
    Employee e8 = {4546, 223222};
    Employee e9 = {7892, 33343233};
    Employee e10 = {12123, 1113311};
    Employee e11= {45623, 2222292};
    Employee e12 = {78932, 3333333};
    Employee* arr[] = {&e1, &e2, &e3, &e4, &e5, &e6, &e7, &e8, &e9, &e10, &e11, &e12};
    int size = 12;

    // Create searchable employee database
    EmpDatabase db = createSearchableEmployeeDB(arr, size);
    if (getErrorCode(db) != 0) {
        printf("Error creating employee database\n");
        return 1;
    }

    // Find employees by SSN
    Employee* emp1 = findEmpBySSN(2222292, db);
    printf("emp1SSN: %d\n", emp1->SSN);
    Employee* emp2 = findEmpBySSN(222222222, db);
    printf("emp2SSN: %d\n", emp2->SSN);
    Employee* emp3 = findEmpBySSN(333333333, db);
    printf("emp3SSN: %d\n", emp3->SSN);

    

    // Find employees by ID
    emp1 = findEmpByID(123, db);
    printf("emp1ID: %d\n", emp1->ID);
    emp2 = findEmpByID(456, db);
    printf("emp2ID: %d\n", emp2->ID);
    emp3 = findEmpByID(789, db);
    printf("emp3ID: %d\n", emp3->ID);

    

    // Free memory used by employee database
    freeEmpDatabase(db);

    return 0;
}

