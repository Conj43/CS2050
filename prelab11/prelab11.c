#include "prelab11.h"

EmpDatabase createSearchableEmployeeDB()
{
    EmpDatabase p;
    p.head = malloc(sizeof(Employee));
    if (!p.head)
    {
        return p;
    }
    else if (p.head)
    {
        p.head->right = NULL;
        p.head->left = NULL;
        p.head->salary = -1;
        p.ec = 0;
        p.size = 0;
    }
    return p;
} // Just inits your struct
Employee * initBranch(int salary)
{
    Employee * new = malloc(sizeof(Employee));
    if(new)
    {
    new->left = NULL;
    new->right = NULL;
    new->salary = salary;
    return new;
    }
    else return NULL;

}

void recursiveInsert(Employee ** root, int salary)
{

    if(*root == NULL)
    {
        Employee * new = initBranch(salary);
        *root = new;
        return;
    }
    else if((*root)->salary > salary)
    {
        recursiveInsert(&((*root)->left), salary);
    }
    else if ((*root)->salary < salary)
    {
        recursiveInsert(&((*root)->right), salary);
    }

}

EmpDatabase insertEmp(Employee * emp, EmpDatabase p)
{
    Employee * temp = p.head;
    if (p.head->salary<0 )
    {
        p.head->salary = emp->salary;
        p.size++;
    }
    if(p.head->salary >=0)
    {
    recursiveInsert(&(temp), emp->salary);
    p.size++;
    }
    return p;
}

void recursiveCount(int min, int max, Employee * p, int *count)
{
    if(p==NULL) return;
    recursiveCount(min, max, p->left, count);
    recursiveCount(min, max, p->right, count);
    if(min <= p->salary && p->salary <= max)
    {
        (*count)++;
    }
    
}
int countEmpsInSalaryRange(int min, int max, EmpDatabase p)
{
    int count = 0;
    recursiveCount(min, max, p.head, &count);
    return count;

}

void recursivePrint(Employee * p)
{
    if (p==NULL) return;
    recursivePrint(p->left);
    recursivePrint(p->right);
    printf("%d\n", p->salary);
}

void printTree(EmpDatabase p)
{
    recursivePrint(p.head);
}

Employee * recursiveSearch(Employee * p, int query)
{
    if (p==NULL) return NULL;
    if (p-> salary == query)
    {
        return p;
    }
    if (p->salary > query)
    {
        return recursiveSearch(p->left, query);
    }
    else if (p->salary < query)
    {
        return recursiveSearch(p->right, query);
    }
}

Employee * binarySearch(EmpDatabase p, int query)
{
    Employee * temp = p.head;
    Employee * look = recursiveSearch(temp, query);
    return look;
}

void freeBranch(Employee * q)
{
    if (q == NULL) return;
    freeBranch(q->left);
    freeBranch(q->right);
    free(q);
}

void freeEmpDatabase(EmpDatabase p)
{
    freeBranch(p.head);
    p.head = NULL;
}
int getErrorCode(EmpDatabase p)
{
    return p.ec;
}