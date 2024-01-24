#include"lab6.h"
// This function will initialize the provided pointer to Node * to an empty list (use a dummy node)
//returns 0 on success, 1 on failure
//paramater is a double node pointer so that the user passes their node * in by reference
int makeList(Node **list)
{
    *list = malloc(sizeof(Node));
    int ec;
    if (*list == NULL) // check if malloc worked
    {
        ec = 1;
    }
    else 
    {
        ec = 0;
    } 
    return ec; // return error code
}
/* This function takes a list, and returns the number of elements on the list
if the number of elements is 0, it returns 0
*/
int getSize(Node *list)
{
    int count = 0;
    Node * q = list->next;
    while (q != NULL)
    {
        q = q->next; // loop thru to end of list and increment count by 1 each time
        count++;
    }
    
    return count;
}

/* This function takes a list and an integer index, and returns the element at the given index, or NULL if the index is
invalid
an invalid index is one which is < 0 or >= getSize(list).
*/
void * getAtIndex(Node *list, int index)
{
    Node * q =list;
    for(int i = 0; i<index; i++)
    {
        q = q->next; // loop to end of list
    }
    if (index < 0) //check if index is negative
    {
        return NULL;
    }
    if (index > getSize(list)) // check if index is bigger than list
    {
        return NULL;
    }
    else
    {
    return q->data; // returns data at given index
    }
}
/* This function takes a pointer to Node and data of type void*, and inserts the given data at the tail of the list. 
 returns 0 on 1 on failure
 */
int insertAtTail(Node *list, void *data)
{
    int ec;
    Node * p = list;
    while(p->next!=NULL)
    {
        p = p->next; // loop to end of list 
    }
    Node * tail = malloc(sizeof(Node));
    if (tail) // check if malloc worked
    {
        tail->data = data;
        tail->next = NULL; // these lines initialize the new node to the given data and set the next equal to null 
        p->next = tail; // then it is added to the end of the list here
        ec = 0;
    }

    if(!p) // if p is NULL, ec is set to 1
    {
        ec = 1;
    }
    return ec;
}

/* This function takes a pointer to Node, and removes the element at the head of the list (if any) 
It will return the data which was removed from the list, or NULL if the list was empty 
*/
void * removeFromHead(Node *list)
{
    Node * q = list; 
    if(q) // make sure list isnt null
    {
    Node * temp = q->next; //temp variable so we can free the removed node
    q->next = q->next->next; // have to bypass dummy node
    void * data = temp->data; // use this to return the data back to user
    free(temp); // free removed node
    return data;
    }
    else return NULL;
}
/* This function takes a pointer to Node *, and frees the memory allocated to the list using pass by reference
user must enter their list using & in main
After freeing, it sets the pointer to NULL. */
void freeList(Node **list)
{
    Node * temp; // use temp so we can free while sequencing thru list
    while(*list != NULL) // check to see when end of list is
    {
        temp = *list;
        *list = (*list)->next;
        free(temp);
    }
    *list = NULL;
} // no return value