#include"prelab7.h"
int main(void)
{
    Queue p;
    p = queueInit();
    int array[] = {6, 98, 23, 54, 7};
    //fill queue
    int ec;
    for(int i = 0; i<5; i++)
    {
        ec = enqueue(array+i,p);
        printf("EC[%d] = %d\n",i,ec );
    }
    printf("size of queue is: %d\n", getQueueSize(p));
    for(int i = 0; i<5; i++)
    {
        int * data = (int*)dequeue(p);
        printf("queue[%d] = %d\n", i, *data);
    }
    printf("size of queue is: %d\n", getQueueSize(p));
    freeQueue(p);
}