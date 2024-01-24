#include"prelab10.h"

int compareByID(const Employee* e1, const Employee* e2) {
    if (e1->ID < e2->ID) {
        return -1;
    } else if (e1->ID > e2->ID) {
        return 1;
    } else {
        return 0;
    }
}

int compareBySSN(const Employee* e1, const Employee* e2) {
    if (e1->SSN < e2->SSN) {
        return -1;
    } else if (e1->SSN > e2->SSN) {
        return 1;
    } else {
        return 0;
    }
}

void mergeSSN(Employee** p, int left, int middle, int right, int (*cmp)(const Employee*, const Employee*)) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    Employee* leftArray[leftSize];
    Employee* rightArray[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = p[left + i];
    }

    for (int i = 0; i < rightSize; i++) {
        rightArray[i] = p[middle + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize) {
        if (cmp(leftArray[i], rightArray[j]) < 0) {
            p[k] = leftArray[i];
            i++;
        }
        else {
            p[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        p[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        p[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSortSSN(Employee** p, int left, int right, int (*cmp)(const Employee*, const Employee*)) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;

    mergeSortSSN(p, left, middle, compareBySSN);
    mergeSortSSN(p, middle + 1, right, compareBySSN);

    mergeSSN(p, left, middle, right, compareBySSN);
}


// 
void mergeID(Employee** p, int left, int middle, int right, int (*cmp)(const Employee*, const Employee*)) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    Employee* leftArray[leftSize];
    Employee* rightArray[rightSize];

    for (int i = 0; i < leftSize; i++) 
    {
        leftArray[i] = p[left + i];
    }

    for (int i = 0; i < rightSize; i++) 
    {
        rightArray[i] = p[middle + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize) {
        if (cmp(leftArray[i], rightArray[j]) < 0) {
            p[k] = leftArray[i];
            i++;
        }
        else {
            p[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        p[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        p[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSortID(Employee** p, int left, int right, int (*cmp)(const Employee*, const Employee*)) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;

    mergeSortID(p, left, middle, compareByID);
    mergeSortID(p, middle + 1, right, compareByID);

    mergeID(p, left, middle, right, compareByID);
}

Employee * binarySearchSSN(int left, int mid, int right, int query, EmpDatabase p)
{
    mid = left + (right - left) / 2; //determines middle each time it recurses through
    if (left >right)
    {
      return NULL;  
    }
    else{
    if (query == p.ssnSort[mid]->SSN) {
            return p.ssnSort[mid]; //if we find the index, then return that index
        } else if (query < p.ssnSort[mid]->SSN) {
            right = mid; // if query is greater than current mid, move the right so we only look at values less than mid now
            return binarySearchSSN(left, mid, right, query, p);
        } else if (query > p.ssnSort[mid]->SSN){
            left = mid + 1; // if query is less than current mid it only looks at values greater than mid and returns this back to the function
            return binarySearchSSN(left, mid, right, query, p);
        }
    }
    
        return NULL;
}

Employee * binarySearchID(int left, int mid, int right, int query, EmpDatabase p)
{
    mid = left + (right - left) / 2; //determines middle each time it recurses through
    if (left >right)
    {
      return NULL;  
    }
    else{
    if (query == p.idSort[mid]->ID) {
            return p.idSort[mid]; //if we find the index, then return that index
        } else if (query < p.idSort[mid]->ID) {
            right = mid; // if query is greater than current mid, move the right so we only look at values less than mid now
            return binarySearchID(left, mid, right, query, p);
        } else if (query > p.idSort[mid]->ID){
            left = mid + 1; // if query is less than current mid it only looks at values greater than mid and returns this back to the function
            return binarySearchID(left, mid, right, query, p);
        }
    }
    
        return NULL;
}


EmpDatabase createSearchableEmployeeDB(Employee** p, int size)
{
    EmpDatabase base = { 0 };
    base.size = size;

    if (size > 0 && *p) {

        // Sort p by ID
        mergeSortID(p, 0, size - 1, compareByID);
        for (int i = 0; i < size; i++) {
            base.idSort[i] = malloc(sizeof(Employee));
            if (base.idSort[i] == NULL) {
                // Handle allocation error
                for (int j = 0; j < i; j++) {
                    free(base.idSort[j]);
                }
                return base;
            }
            *base.idSort[i] = *p[i];
        }
    }
    if (size > 0 && *p)
    {
        // Sort p by SSN
        mergeSortSSN(p, 0, size - 1, compareBySSN);
        for (int i = 0; i < size; i++) {
            base.ssnSort[i] = malloc(sizeof(Employee));
            if (base.ssnSort[i] == NULL) {
                // Handle allocation error
                for (int j = 0; j < i; j++) {
                    free(base.ssnSort[j]);
                }
                return base;
            }
            *base.ssnSort[i] = *p[i];
        }
    }
    return base;
}
int searchSSN(int query, int mid, int left, int right,  EmpDatabase p)
{
    if (left>right)
    {
        return -1;
    }
    if (right>=left)
    {
    mid = (left + right) / 2;
    if (query == p.ssnSort[mid]->SSN) {
            return mid; //if we find the index, then return that index
        } else if (query < p.ssnSort[mid]->SSN) {
            right = mid; // if query is greater than current mid, move the right so we only look at values less than mid now
            return searchSSN(query,  mid, left, right,p);
        } else if (query > p.ssnSort[mid]->SSN){
            left = mid +1; // if query is less than current mid it only looks at values greater than mid and returns this back to the function
            return searchSSN(query,  mid, left, right,p);
        }
    }
    return -1;
    }

int countEmpsInSSNRange(int min, int max, EmpDatabase p)
{
    int minindex, maxindex;
    int mid, left = 0, right = (p.size)-1;
    mid = (left + right) / 2; //determines middle each time it recurses through
    minindex = -1;
    maxindex = -1;
    minindex = searchSSN(min, mid,left, right,  p);
    maxindex = searchSSN(max, mid,left, right,  p);

    if (minindex > 0 && maxindex > 0)
    {
    return maxindex-minindex;
    }
    return -1;
}
               

Employee * findEmpBySSN(int SSN, EmpDatabase p)
{
    int size = p.size;
    int left = 0, right = size - 1;
    int mid = left + (right - left) / 2;
    return binarySearchSSN(left, mid,right, SSN, p);
}

Employee * findEmpByID(int ID, EmpDatabase p)
{
    int size = p.size;
    int left = 0, right = size - 1;
    int mid = left + (right - left) / 2;
    return binarySearchID(left, mid, right, ID, p);
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
