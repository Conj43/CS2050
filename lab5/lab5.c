#include"lab5.h"
/* makeList: this function uses the list that the user passed in and allocates memory for it 
or you could say it sets it equal to an empty list and this is to initialize the list
this is done using pass by reference, so we dereference the list and set it equal to that allocated memory
i am a little confused because we were taught to always check if malloc worked, but the lab says the function will always 
return 0 so i just have it always return 0
we malloc enough space for a struct of type Node

param: the lone parameter is a struct of type node that is going to be used to initialize this linked list
the user must pass in the this pointer of type node using the &(address) operator because we are using pass by reference
in this function*/
int makeList(Node **list)
{
    *list = NULL; // dereference pointer to use pass by reference and equal to space of a Node

    return 0; // always returns 0
}

/* getSize: this function finds the number of nodes or things in a linked list and returns it back to the user
as an integer
we use a while loop so when p doesnt equal null, we keep cycling and using the count variable to increase the count by one
each time the while loops through
we set p = p->next so that we have a way of sequencing through the linked list and we return the variable count

param: the only parameter is a pointer struct of type Node that is passed in regularly by the user*/
int getSize(Node *list)
{
    int count = 0;
    while (list != NULL) //we set p = p->next and it won't equal null until we hit the last node of the linked list
    {
        list = list->next; // sequence through list
        count++; //increase by 1
    }
    return count; //return the number of nodes in the list
}

/* insertAtTail: this function cycles through to the end of the list and sets the list->next of the last pointer equal to the 
new node
i used my own createnode function to create the new node and i also checked if it was null
the function returns 1 if it wasn't successful and 0  if it was successful

param: the node * that is passed into this function must be passed by reference using the & operator
the void * data can be of any type and that will be stored in the node that is inserted at the tail*/
int insertAtTail(Node **list, void *data)
{
    int ec;
    Node * p = *list;
    if(*list == NULL)
    {
        Node * q = createNode(data);
        *list = q;
        ec = 0;
    }
        else
    {
        while(p->next!=NULL)
        {
            p = p->next;
        }
        Node * tail = createNode(data);
        p->next = tail;
        ec = 0;
    }
    if(!p)
    {
        ec = 1;
    }
    return ec;
}

/*  createNode: I dont know if we need this function for this specific lab, but it definitely makes it easier to imagine if 
i have this function
this function sets a node pointer equal to some allocated space the size of a Node, then assign the value of p->data
to whatever was passed into the function
then p->next is set to NULL so that it can be set equal to something else, or stay NULL if it is at the tail of the list
i use if(p) to check if malloc worked, because it p is null then none of that will work and the function will return null
i made this function to use it in other functions
if this creating of a node is successful, then the node * is returned back to the user, if not, it is returned null

param: the parameter is a void * which can be anything, and it is used to set the data in the struct equal to whatever 
the user passes in*/
Node * createNode(void* data)
{
    Node * p;
    p = malloc(sizeof(Node));
    if (p)
    {
        p->data = data;
        p->next = NULL;
    }
    return p;
}
/* this function removes the head of the list and uses the data in the head that is being removed and returns it to the user
we used two temp variable to be able to set our list equal to them and use another one to store the data that will be returned 
to the user
we used createnode to create a node for the head that we are taking out
then we have to dereference the list and set it equal to the new list with a new head and set the previous head pointer equal to NULL

param: just a node * that needs to be passed by reference*/
void * removeFromHead(Node **list)
{
    if(*list)
    {
    Node * temp = *list;
    *list = (*list)->next;
    void * data = temp->data;
    free(temp);
    return data;
    }
    else return NULL;
}
/* this function frees every item in a list
i kept getting weird error codes when i dereferenced list so i just used new nodes and set those equal to the list that was passed in
by the user
all this does is loop through until the list == NULL and it uses a temp variable to cycle through by freeing the lol variable
and then the temp variable is set equal to the next item in the list

param: the address of a node * list that will be passed by reference */
void freeList(Node **list)
{
    Node * temp;
    temp = *list;
    Node * lol;
    while(temp != NULL)
    {
        lol = temp;
        temp = temp->next;
        free(lol);
    }
    *list = NULL;
    temp = NULL;
    lol = NULL;
    
}
