#include "lab11.h"
int main(void)
{
    treeInfo e1 = {5};
    treeInfo e2 = {120};
    treeInfo e3 = {15};
    treeInfo e4 = {20};
    treeInfo e5 = {30};
    treeInfo e6 = {25};
    treeInfo e7 = {70};
    treeInfo e8 = {90};
    treeInfo e9 = {40};
    treeInfo e10 = {55};
    treeInfo e11= {60};
    treeInfo e12 = {2};
    treeInfo * arr[] = {&e1, &e2, &e3, &e4, &e5, &e6, &e7, &e8, &e9, &e10, &e11, &e12};
    int size = 12;


    BST * p = initBST();
    int ec = 0;
    for(int i = 0; i<size; i++)
    {
        ec = insertBST(p, arr[i]->data);
        printf("ec[%d] = %d\n", i, ec);
    }
    printf("Size of the BST is %d\n", getSizeBST(p));
    printf("here is the pieces printed in preorder:\n");
    preOrderPrintBST(p);
    printf("The min value in the BST is %d\n", getMinBST(p));
    freeBST(p);
}