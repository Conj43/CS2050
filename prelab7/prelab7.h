#include<stdio.h>
#include<stdlib.h>


typedef struct queueInfo QueueInfo;

typedef struct queue{
    QueueInfo * j;
} Queue;

/* This function returns the error code from the most
recently executed queue operation. 0 implies success,
1 implies out-of-memory error. Some functions may
document additional error conditions. NOTE: All
queue functions assign an error code. */
int getQueueErrorCode(Queue p);
/* This function returns an initialized Queue variable.
Every queue variable must be initialized before
applying subsequent queue functions. */
Queue queueInit();
/* This function enqueues an object into the queue.
For convenience, error code is returned directly
(and also can be obtained via getQueueErrorCode) */
int enqueue(void * data, Queue p);
/* This function performs dequeue and returns
object at front of queue. NULL is returned
if queue is empty and error code is set to 2.
NOTE: User should check error code if null
objects are permitted in the queue. */
void * dequeue(Queue p);
/* This function returns the number of objects
in the queue. */
int getQueueSize(Queue p);
/* This function uninitializes a queue and frees all
memory associated with it. NOTE: value of Queue
variable is undefined after this function is
applied, i.e., it should not be used unless
initialized again using queueInit. */
void freeQueue(Queue p);