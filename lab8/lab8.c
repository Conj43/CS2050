#include"lab8.h"
// this is my implementation for my pq ADT
//it has a linked list with nodes that includes the priority integer
typedef struct nodeStruct{
    struct nodeStruct *next;
    void * data;
    int priority;
} Node;
//we only need a head or front pointer and a size and error code integer for this implementation
typedef struct Info{
    Node *front;
    int size, ec;
} Info;

//-1
// O(1)
// This function returns the error code from the most recently executed PQueue operation. 0
//implies success, 1 implies out-of-memory error. Some functions may document additional error conditions.
// parameter is a pq variable thats been initialized by pqinit
int pqGetErrorCode(PQueue q)
{
    return q.info->ec;
}
//-2
// O(1)
/* just initializes a pqueue variable; sets ec to 1 on failure and returns null
sets ec to 0 and returns an initialized pqueue variable on success
in main user should set their unitialized variable equal to this function and it will initialize it for them*/
PQueue pqInit()
{
    PQueue w;
    w.info = malloc(sizeof(Info));
    if (w.info == NULL) // check if malloc worked
    {
        w.info->ec = 1;
        w.info = NULL;
        return w;
    }
    else
    {
        w.info->size = 0;
        w.info->ec = 0;
        w.info->front = NULL;
        return w; // returns an initialized pqueue variable
    }
}
//-3
// O(n)
/* function takes a void * data, priority integer and a pqueue variable and inserts a new node in the pqueue
since it takes O(n) complexity we can sort our queue in order using its priority
highest priority in the front and lowest priority in the rear
will return 0 on success, 1 on failure using built in ec in our pqueue*/
int pqInsert(void *data, int priority, PQueue q)
{
    if (q.info->front != NULL) // check if empty
    {
    Node * w = malloc(sizeof(Node));
    if (w== NULL) // check if malloc worked
    {
        q.info->ec = 1;
    }
    if (w)
    {
    w->data = data; // this initializes our new Node
    w->next = NULL;
    w->priority = priority;
    if (priority == q.info->front->priority) // if new Node and front have the same priority, the first variable there will get priority FIFO
    {
        Node * r = q.info->front;
        w->next = r->next;
        r->next = w;
        q.info->size++;
        q.info->ec = 0;
        return q.info->ec;
    }
    if (priority > q.info->front->priority) // if new Node has greater priority, it will be inserted at the head
    {
        Node * temp = q.info->front;
        q.info->front = w;
        w->next = temp;
        q.info->size++;
        q.info->ec = 0;
        return q.info->ec;
    }
    if (priority < q.info->front->priority) // if new Node has lower priority, we sort through queue until we find the spot where it goes
    {
    Node * r = q.info->front;
    while(priority < r->priority)
    {
        if ( r->next == NULL) // this case is for when the new Node has the lowest priority
        {
            r->next = w;
            w->next = NULL;
            q.info->size++;
            q.info->ec = 0;
            return q.info->ec;
        }
        if(r->next != NULL) // this case is when the new Node has a priority in the middle
        {
            Node * f = r->next; // use this variable to peek ahead at the next priority so we dont go too far
        if ( f->priority < priority)
        {
            r->next = w;
            w->next = f;
            q.info->size++;
            q.info->ec = 0;
            return q.info->ec;
        }
        
        }
        if(r->priority == priority)
        {
            
            w->next = r->next;
            r->next = w;
            q.info->size++;
            q.info->ec = 0;
            return q.info->ec;
        }
        r = r->next;
        
    }
    return q.info->ec;
    }
    
    
    }
    }
    if (q.info->front == NULL) // this is if the pqueue is empty and has been initialized
    {
    Node * w = malloc(sizeof(Node));
    if (w== NULL)
    {
        q.info->ec = 1;
    }
    if (w)
    {
    w->data = data;
    w->next = NULL;
    w->priority = priority;
    q.info->front = w; //set our new front to our only Node
    q.info->size++;
    q.info->ec = 0;
    }
    }
    return q.info->ec;
}
//-4
// O(1)
/* this function takes a pqueue variable and removes the Node with the highest priority
we can do this in O(1) because we inserted the Nodes in sorted order, so now we can just remove from front
because that is where the highest priority is
if two nodes have same priority, it is FIFO
returns the void * data in the removed node
the removed node is freed and the new head is the next highest priority node
returns NULL on failure and sets ec= 2 if pqueue is empty*/
void * pqRemoveMax(PQueue q)
{
    if(q.info->front)
    {
    Node * temp = q.info->front;
    void * data = q.info->front->data;
    q.info->front = q.info->front->next;
    q.info->size--;
    free(temp);
    return data;
    } 
    if (!q.info->front)
    {
        q.info->ec = 2;
        return NULL;
    }
    return NULL;
}
//-5
// O(1)
/* this function takes a pqueue variable and returns the data with the highest priority
if the pqueue is empty it returns NULL
we can do this in O(1) because we sorted our array by priority when the nodes were inserted
*/
void * pqPeek(PQueue q)
{
    if (q.info == NULL) return NULL;
    return q.info->front->data;
}
//-6
// O(1)
/* this function takes a pqueue variable and returns the size of that pqueue, if empty it returns 0
assuming we used pqinit to initialize it
we can do this in O(1) because of our implementation
our size is embedded in the info struct*/
int pqGetSize(PQueue q)
{
    return q.info->size;
}
//-7
// O(n)
/* this function takes a pqueue variable and frees each node in it
it takes O(n) because we need to sequence through each node and free it 
it has no return value because all we are doing is freeing our pqueue then setting it equal to NULL
so that it cant be used again unless we initialize it using pqinit*/
void pqFree(PQueue q)
{
    {
    Node * temp;
    while (q.info->front)
    {
    temp = q.info->front;
    q.info->front = q.info->front->next;
    free(temp);
    }
    free(q.info);
    q.info = NULL;
}
}