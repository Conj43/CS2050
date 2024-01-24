#include"prelab5.h"

List * initList(int* ec)
{
    List * p;
    p = malloc(sizeof(List));
    
    if (p == NULL)
    {
        *ec = 1;
    }
    else 
    {
        *ec = 0;
        p->next = NULL;
        p->object = 0;
    } 
    return p;
}

List * createNode(int obj)
{
    List * p;
    p = malloc(sizeof(List));
    if (p)
    {
        p->object = obj;
        p->next = NULL;
    }
    return p;
}

List * insertAtHead(int obj, List* p, int* ec)
{
    List * q;
    q = createNode(obj);
    if (q == NULL)
    {
        *ec = 1;
    }
    else
    {
    q->next = p->next;
    p->next = q;
    *ec = 0;
    }
    return p;
}

int getAtIndex(int index, List* p)
{
    List * net = p->next;
    for(int i = 0; i<index; i++)
    {
        net = net->next;
    }
    return net->object;
}

int getListLength(List* p)
{
    int count = 0;
    List * q = p->next;
    while (q != NULL)
    {
        q = q->next;
        count++;
    }
    return count;
}

List * freeList(List* p)
{
    List * temp;
    while(p != NULL)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
    return NULL;
}