#include"prelab8.h"

typedef struct nodeStruct{
    struct nodeStruct *next;
    void * data;
    int priority;
} Node;

typedef struct PQueueInfo{
    Node *front;
    Node * rear;
    int size, ec;
} PQInfo;


int pqGetErrorCode(PQueue w)
{
    return w.info->ec;
}

PQueue pqInit()
{
    PQueue w;
    w.info = malloc(sizeof(PQInfo));
    if (w.info == NULL)
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
        w.info->rear = NULL;
        return w;
    }

}

int pqInsert(void * data, int priority, PQueue w)
{
    if (w.info->front != NULL)
    {
    Node * q = malloc(sizeof(Node));
    if (q == NULL)
    {
        w.info->ec = 1;
    }
    if (q)
    {
        
    }
    }
    if (w.info->front == NULL)
    {
    Node * q = malloc(sizeof(Node));
    if (q== NULL)
    {
        w.info->ec = 1;
    }
    if (q)
    {
    q->data = data;
    q->next = NULL;
    q->priority = priority;
    w.info->front = q;
    w.info->rear = q;
    w.info->size++;
    w.info->ec = 0;
    }
    }
    return w.info->ec;
}

void * pqRemoveMax(PQueue w)
{
    if (w.info == NULL)
    {
        w.info->ec = 2;
        return NULL;
    }
    int maxPri = w.info->front->priority;
    int count;
    Node * temp;
    Node * t;
    for(temp = w.info->front; temp != NULL; temp = temp->next)
    {
        if(temp->priority > maxPri)
        {

        }
    }

}

int pqGetSize(PQueue w);

void pqFree(PQueue w);
