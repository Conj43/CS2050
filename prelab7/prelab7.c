#include"prelab7.h"

typedef struct nodeStruct{
    struct nodeStruct *next;
    void * data;
} Node;

typedef struct queueInfo{
    Node *front;
    Node * rear;
    int size, ec;
} QueueInfo;

int getQueueErrorCode(Queue p)
{
    return p.j->ec;
}
Queue queueInit()
{
    Queue p;
    p.j = malloc(sizeof(QueueInfo));
    if (p.j==NULL)
    {
        p.j->ec = 1;
        return p;
    }
    else
    {
    p.j->rear = NULL;
    p.j->front = NULL;
    p.j->ec = 0;
    p.j->size = 0;
    return p;
    }
}
int enqueue(void * data, Queue p)
{
    if (p.j->front != NULL)
    {
    Node * q = malloc(sizeof(Node));
    if (q== NULL)
    {
        p.j->ec = 1;
    }
    if (q)
    {
    q->data = data;
    q->next = NULL;
    p.j->rear->next = q;
    p.j->rear = q;
    p.j->size++;
    p.j->ec = 0;
    }
    }
    if (p.j->front == NULL)
    {
    Node * q = malloc(sizeof(Node));
    if (q== NULL)
    {
        p.j->ec = 1;
    }
    if (q)
    {
    q->data = data;
    q->next = NULL;
    p.j->front = q;
    p.j->rear = q;
    p.j->size++;
    p.j->ec = 0;
    }
    }
    return p.j->ec;
}
void * dequeue(Queue p)
{
    if(p.j->front)
    {
    Node * temp = p.j->front;
    void * data = p.j->front->data;
    p.j->front = p.j->front->next;
    p.j->size--;
    free(temp);
    return data;
    } 
    if (!p.j->front)
    {
        p.j->ec = 2;
        return NULL;
    }
    return NULL;
}
int getQueueSize(Queue p)
{
    return p.j->size;
}
void freeQueue(Queue p)
{
    Node * temp;
    while (p.j->front)
    {
    temp = p.j->front;
    p.j->front = p.j->front->next;
    free(temp);
    }
    free(p.j);
    p.j = NULL;
}