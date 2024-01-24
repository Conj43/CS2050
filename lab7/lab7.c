#include"lab7.h"
// this is a list struct. it is the lowest layer of our implementation and just includes a next pointer and data that will be held in Nodes
typedef struct nodeStruct{
    struct nodeStruct *next;
    void * data;
} Node;

/* this is the info struct for our stack. it has a front pointer and rear pointer that point to the 
front and read node respectively
we also used an integer size and error code to make our implementation more efficient*/
typedef struct Info{
    Node *front;
    Node * rear;
    int size, ec;
} Info;

/*initStack is done in O(1) time and it has no parameters. 
this function initalizes a stack variable
sets error code to 1 if malloc fails and 0 if malloc works successfully
after it initializes our info, rear and front variables, it returns a stack variable that can be used
if malloc fails we also set the info pointer to null and return that to the user
in order to use, the user must set their stakc variable equal to initStack
ex: 
Stack q = initStack();
*/ 
Stack initStack()
{
    Stack s;
    s.info = malloc(sizeof(Info));
    if (s.info==NULL)
    {
        s.info = NULL;
        s.info->ec = 1;
        return s;
    }
    else
    {
    s.info->rear = NULL;
    s.info->front = NULL;
    s.info->ec = 0;
    s.info->size = 0;
    return s;
    }
}

/* getSize is done in O(1) time and it just returns an integer that represents size of the stack
the size is stored in our info struct so we can access it using our stack variable
if size is 0, it returns 0
parameter is a stack variable that has been initalized using initStack*/
int getSize(Stack s)
{
    return s.info->size;
}

/* this function is done in O(1) time because we can access it using our stack variable
a stack variable is the only parameter, and we only need one line because the data
can be accessed very quickly through our info struct then our list struct
it returns a void* which is data in our struct
it peeks at the data at the top of the stack, and we use our Node * front to represent the top
of our stack*/
void * peekStack(Stack s)
{
    return s.info->front->data;
}

/*  This function takes a stack, as well as a data item. It will push the item onto the top of the stack,
and return 0 if insertion was successful, or 1 if it was not
this is done in O(1) time because we have a rear and front pointer in our struct
*/
int pushStack(Stack s, void *data)
{
    if (s.info->rear != NULL) // this checks if the stack is empty, because if it was empty then s.info->rear would == NULL
    {
    Node * q = malloc(sizeof(Node));
    if (q== NULL)
    {
        s.info->ec = 1; // change ec if malloc fails
    }
    if (q)
    {
    q->data = data;
    q->next = s.info->front; // puts q in front of the current front node
    s.info->front = q; // dets front equal to new node
    s.info->size++; // increase size in struct by one
    s.info->ec = 0; // implies success
    }
    }
    if (s.info->rear == NULL) // this checks if the stack is empty, because if it was empty then s.info->rear would == NULL
    {
    Node * q = malloc(sizeof(Node));
    if (q== NULL)
    {
        s.info->ec = 1; // check if malloc fails
    }
    if (q)
    {
    q->data = data;
    q->next = NULL;
    s.info->front = q; // this would be first node, so front and rear are set to this new node
    s.info->rear = q; // this node will be rear until either pop is used for the whole stack, or it is freed
    s.info->size++;
    s.info->ec = 0;
    }
    }
    return s.info->ec; // use error code in struct to return integer 0 success or 1 failure
}

/* This function takes a stack, and pops the data item from the top of the stack. It returns the item
popped from the stack, or NULL if the stack is empty.
this is done in O(1) time because we can use our front pointer to set it equal to our next pointer
and that only takes O(1) time*/
void * popStack(Stack s)
{
    if(s.info->front) // check to see if stack is empty
    {
    Node * temp = s.info->front;
    void * data = s.info->front->data;
    s.info->front = s.info->front->next;
    s.info->size--;
    free(temp);
    return data;
    } 
    if (!s.info->front) // check to see of stack empty
    {
        s.info->ec = 2; // if empty ec set to 2 to let user know that stack is empty
    }
    return NULL; // have to return something, so if empty then returns NULL;
}

/* This function takes a stack, as well as an index. It returns the element at the given index with-
out removing it, relative to the top of the stack. the item on the top is at index 0, the item below
that is 1, and so on. If the index is not valid for the stack, it returns NULL.
this will take O(n) time because we don't know what the index will be, so if it is at the middle of the list, 
we will have to sequence through and find the index which takes O(n) time where n is the size of the stack*/
void * getAtIndex(Stack s, int index)
{
    if (index > getSize(s) || index<0) // if index is larger than size of stack OR index is negative, return NULL;
    {
        return NULL;
    }
    else
    {
    Node * q = s.info->front; // use a temp node pointer to sequence through the stack
    int i = 0;
    while(i != index)
    {
        q = q->next;
        i++;
    }
    void * data = q->data;
    return data; // returns data in node at given index
    }
}

/* This function takes a stack, and frees all memory allocated to the stack. 
this takes O(n) time because we are sequencing thru the stack and freeing each node
where n is the size of the stack
*/
void freeStack(Stack s)
{
    Node * temp;
    while (s.info->front != NULL) // check if stack is empty
    {
    temp = s.info->front;
    s.info->front = s.info->front->next;
    free(temp);
    }
    free(s.info); // we malloced in the initialization function, so need to make sure to free that
    s.info = NULL; // set equal to NULL so that we cant use this again unless we initialize it again using initStack
}