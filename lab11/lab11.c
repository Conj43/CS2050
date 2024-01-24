#include "lab11.h"
// these are all the helper functions i used, i put their prototypes at the top
treeInfo * initBranch(int data);
void recursiveInsert(treeInfo ** root, int data, int * ec);
int recursiveMin(treeInfo * p);
void recursivePrint(treeInfo * p);
void freeTree(treeInfo * q);
/* this function is used to initialize a pointer to a BST struct
I used my BST so that struct only points the the head of the tree, and it also holds the size, 
typedef struct treeInfo {
    int data;
    struct treeInfo * right;
    struct treeInfo * left;
}treeInfo;

typedef struct BST {
    treeInfo * head;
    int size;
}BST;
this is what my structs look like
anyways my function takes nothing and returns a pointer to a BST, it mallocs a BST to initialzie the BST pointer
and also mallocs for the head of the tree
we then initalize left and right of the head to NULL and data and size to 0 and can the return the BST pointer back to the user*/
BST * initBST()
{
{
    BST * p = malloc(sizeof(BST));
    p->head = malloc(sizeof(treeInfo));
    if (!p) // check if malloc worked, if it didnt then this will return NULL
    {
        return p;
    }
    else if (p)
    {
        p->head->right = NULL;
        p->head->left = NULL;
        p->head->data = 0;
        p->size = 0;
    }
    return p; // returns BST pointer
} 
}

/* this is a helper function I used to initialize each new branch of the BST with 
it is similar to the one before but it takes an integer data and returns a pointer to a treeInfo struct which i call
'branches' it just initializes a new branch so its left and right are NULL and it puts the data in the correct place in the new
branch*/
treeInfo * initBranch(int data)
{
    treeInfo * new = malloc(sizeof(treeInfo));
    if(new) // check if malloc worked
    {
    new->left = NULL;
    new->right = NULL;
    new->data = data;
    return new;
    }
    else return NULL; // return NULL if malloc didnt work

}
/* another helper function that is used to recursively go through the tree to find where to insert
it takes a double pointer to a treeInfo struct, and integer data, and a pointer ec
i passed in ec by reference to check if malloc worked, because if it didn't then i change it to 1 and end up returning 
it in the next function
i am honestly not sure if the root needs to be a double pointer, but i got it to work like that in the prelab so i kept it similar
it basically checks if the current treeInfo is NULL, if so it creates a new branch and inserts it at the current branch
if the data is less than the current root, the function returned is the same but using root->left because that is the way we sequence it
it is vice versa if the data is greater than the current root
basically, we just sequence throguh until we find the end because we are just using a simple insert*/
void recursiveInsert(treeInfo ** root, int data, int * ec)
{

    if(*root == NULL)
    {
        treeInfo * new = initBranch(data);
        if (new == NULL) // check if malloc worked
        {
            *ec = 1;
        }
        *root = new; // set new branch to current root
        return;
    }
    else if((*root)->data > data)
    {
        recursiveInsert(&((*root)->left), data, ec); // recursive call 
    }
    else if ((*root)->data < data)
    {
        recursiveInsert(&((*root)->right), data, ec); // recursive call
    }

}
// O(log(n))
/* this function inserts a new branch into the bottom of our BST
it takes a pointer to a BST and data to insert into the new branch
it returns 0 on success and 1 on failure
if the size == 0 then we know there hasnt been anything added, and since we already malloc'ed
all we need to do is insert the data into the head node
as long as malloc worked, we should return 0 in that case
if the sie is > 0 that means we have inserted a new branch, and need to use recursiveInsert to find where
to insert the new branch
each time a new branch is inserted we increase p->size by 1
we assume that there will be no duplicates in the data*/
int insertBST(BST *tree, int data)
{
    int ec = 0;
    treeInfo * temp = tree->head;
    if (tree->size == 0) // if tree empty
    {
        tree->head->data = data;
        tree->size++;
        return ec; // should be 0 because we already malloc'ed
    }
    if(tree->size > 0) // if tree not empty
    {
    recursiveInsert(&(temp), data, &ec);
    tree->size++;
    return ec; // 0 on success, 1 on failure, it wouldve changed in the previous function 
    }
    else return ec;
    
}
// O(1)
/* this function takes a pointer to a BST and just returns an int which indicates how many 
branches are in the tree
we assume the BST * has been initalized by initBST 
if the tree is empty it returns 0*/
int getSizeBST(BST *tree)
{
    return tree->size;
}
/* this is a helper fuction I used that finds the minimum value in the tree
it does this by basically just sequencing to the left-most element and returning it
since we know if a value is less than the current node it goes to the left, we can always just go to the 
left-most element and it will be the minimum
it returns the minimum value in the tree and its only parameter is a treeInfo pointer, which is the head of the 
BST*/
int recursiveMin(treeInfo * p)
{
    if(p->left == NULL) // if the next element to the left is NULL, we know we are at the bottom/minimum
    {
        return p->data;
    }
    else if (p->left != NULL) // if there is an element to the left of the current one, we aren't at the minimum element
    {
        return recursiveMin(p->left);
    }
    return 0;
}
/* this functions takes a pointer to a BST and returns the minimum value in the tree
it does this using the recursiveMin function that allows us to recursively go to the left-most element and return it
we assume that the tree is not empty*/
// O(log(n))
int getMinBST(BST *tree)
{
    return recursiveMin(tree->head); // pass in the head of the tree to start at top
}
/* this is a helper function I used to use recursion to print the tree in preorder
it takes a treeInfo pointer, which we the head of the head of the tree so it works properly
if the treeInfo == NULL then we know we are at the end and it stops
besides that, it just prints the current branch then runs the function for each the left and right
branches until it hits NULL which is the end
if the tree is empty it does nothing*/
void recursivePrint(treeInfo * p)
{
    if (p==NULL) return;
    printf("%d\n", p->data);
    recursivePrint(p->left);
    recursivePrint(p->right);
}
/* this function prints the BST in PreOrder 
it takes a BST pointer and it doesnt return anything, it just prints each element out using the previous recursive function*/
// O(n)
void preOrderPrintBST(BST *tree)
{
    recursivePrint(tree->head);
}
/* this is the last helper function that frees all memory that was allocated for the BST
it takes a treeInfo pointer, which should be the head and it just recurses through and frees each 
element
we need to run the function for the left and right before we free the current one, or else we might lose the memeory 
already and then free wouldn't know what we are talking about for the left and right elements
it returns nothing, just frees all memory*/
void freeTree(treeInfo * q)
{
    if (q == NULL) return;
    freeTree(q->left);
    freeTree(q->right);
    free(q);
}
// O(n)
/* this function just uses the previous function to recurse through and free all memory associated with the 
BST
we also can't forget to free the tree because we malloc'ed it in our original function to initialize it
the parameter is just a BST pointer and it returns nothing, just frees everything*/
void freeBST(BST *tree)
{
    freeTree(tree->head);
    free(tree);
}