#include"prelab10.h"

int main(void) {
    // Sample employees
    Employee e1 = {10, 10};
    Employee e2 = {5, 75};
    Employee e3 = {15, 0};
    Employee e4 = {20, 35};
    Employee e5 = {30, 50};
    Employee e6 = {25, 45};
    Employee e7 = {70, 15};
    Employee e8 = {90, 20};
    Employee e9 = {40, 95};
    Employee e10 = {55, 100};
    Employee e11= {60, 60};
    Employee e12 = {65, 90};
    Employee* arr[] = {&e1, &e2, &e3, &e4, &e5, &e6, &e7, &e8, &e9, &e10, &e11, &e12};
    int size = 12;

    // Create searchable employee database
    EmpDatabase db = createSearchableEmployeeDB(arr, size);
    if (getErrorCode(db) != 0) {
        printf("Error creating employee database\n");
        return 1;
    }
    printf("Sorted by SSN:\n");
    for(int i = 0; i<size; i++)
    {
        printf("Employee[%d] SSN: %d\n", i, db.ssnSort[i]->SSN);
    }
    printf("\nSorted by ID:\n");
    for(int i = 0; i<size; i++)
    {
        printf("Employee[%d] ID: %d\n", i, db.idSort[i]->ID);
    }

    printf("range between = %d\n", countEmpsInSSNRange(4, 75, db));

    // Find employees by SSN
    Employee* emp1 = findEmpBySSN(0, db);
    printf("emp1SSN: %d\n", emp1->SSN);
    Employee* emp2 = findEmpBySSN(90, db);
    printf("emp2SSN: %d\n", emp2->SSN);
    Employee* emp3 = findEmpBySSN(100, db);
    printf("emp3SSN: %d\n", emp3->SSN);

    

    // Find employees by ID
    emp1 = findEmpByID(5, db);
    printf("emp1ID: %d\n", emp1->ID);
    emp2 = findEmpByID(70, db);
    printf("emp2ID: %d\n", emp2->ID);
    emp3 = findEmpByID(30, db);
    printf("emp3ID: %d\n", emp3->ID);

    

    // Free memory used by employee database
    freeEmpDatabase(db);

    return 0;
}