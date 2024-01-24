#include"lab8.h"
int main(void)
{
    PQueue p;
    p = pqInit();
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int priority[] = {2, 5, 3, 7, 3, 8, 2, 4, 0, 10};
    //fill queue
    int ec;
    for(int i = 0; i<10; i++)
    {
        ec = pqInsert(array+i, priority[i], p);
        printf("EC[%d] = %d\n",i,ec );
    }
    printf("size of the priority queue is: %d\n", pqGetSize(p));
    int * data = (int*)pqPeek(p);
    printf("the element with the highest priority in the queue is: %d\n", *data);
    for(int i = 0; i<10; i++)
    {
        int * data = (int*)pqRemoveMax(p);
        printf("priority queue[%d] = %d\n", i, *data);
    }
    printf("size of queue is: %d\n", pqGetSize(p));
    pqFree(p);
}