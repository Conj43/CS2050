#include"prelab9.h"

EmpDatabase createSearchableEmployeeDB(Employee** p, int size)
{
    Employee temp;
    EmpDatabase base = {0};
    base.size = size;
    if (size > 0 && *p)
    {
        // Sort p by SSN
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (p[j]->SSN > p[j + 1]->SSN)
                {
                    temp = *p[j];
                    *p[j] = *p[j + 1];
                    *p[j + 1] = temp;
                }
            }
        }
        // Allocate memory for ssnSort array and copy sorted p
        for (int i = 0; i < size; i++)
        {
            base.ssnSort[i] = malloc(sizeof(Employee));
            if (base.ssnSort[i] == NULL)
            {
                // Handle allocation error
                for (int j = 0; j < i; j++)
                {
                    free(base.ssnSort[j]);
                }
                return base;
            }
            *base.ssnSort[i] = *p[i];
        }

        // Sort p by ID
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (p[j]->ID > p[j + 1]->ID)
                {
                    temp = *p[j];
                    *p[j] = *p[j + 1];
                    *p[j + 1] = temp;
                }
            }
        }

        // Allocate memory for idSort array and copy sorted p
        for (int i = 0; i < size; i++)
        {
            base.idSort[i] = malloc(sizeof(Employee));
            if (base.idSort[i] == NULL)
            {
                // Handle allocation error
                for (int j = 0; j < i; j++)
                {
                    free(base.ssnSort[j]);
                }
                return base;
            }
            *base.idSort[i] = *p[i];
        }
    }
    return base;
}

               

Employee * findEmpBySSN(int SSN, EmpDatabase p)
{
    int size = p.size;
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (SSN == p.ssnSort[mid]->SSN) {
            return p.ssnSort[mid];
        } else if (SSN < p.ssnSort[mid]->SSN) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return NULL;
}

Employee * findEmpByID(int ID, EmpDatabase p)
{
    int size = p.size;
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ID == p.idSort[mid]->ID) {
            return p.idSort[mid];
        } else if (ID < p.idSort[mid]->ID) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return NULL;
}
void freeEmpDatabase(EmpDatabase p)
{
    for(int i = 0; i<p.size; i++)
    {
        free(p.idSort[i]);
        free(p.ssnSort[i]);
    }
}
int getErrorCode(EmpDatabase p)
{
    return p.ec;
}

