#include <stdio.h>
#include <stdlib.h>


typedef struct treeInfo {
    int data;
    struct treeInfo * right;
    struct treeInfo * left;
}treeInfo;

typedef struct BST {
    treeInfo * head;
    int size;
}BST;
// O(1)
BST * initBST();
// O(log(n))
int insertBST(BST *tree, int data);
// O(1)
int getSizeBST(BST *tree);
// O(log(n))
int getMinBST(BST *tree);
// O(n)
void preOrderPrintBST(BST *tree);
// O(n)
void freeBST(BST *tree);