#include<stdio.h>
#include<stdlib.h>

typedef struct PQueueInfo PQInfo;

typedef struct{
    PQInfo * info;
}PQueue;

/* This function returns the error code from the most
recently executed PQueue operation. 0 implies success,
1 implies out-of-memory error. Some functions may
document additional error conditions. NOTE: All
queue functions assign an error code. */
int pqGetErrorCode(PQueue w);
/* This function returns an initialized PQueue variable.
Every queue variable must be initialized before
applying subsequent queue functions. */
PQueue pqInit();
/* This function enqueues an object and its associated
priority (int) into the PQueue.
For convenience, error code is returned directly
(and also can be obtained via pqGetErrorCode) */
int pqInsert(void * data, int priority, PQueue w);
/* This function returns the user object with
highest priority. NULL is returned if PQueue
is empty and error code is set to 2.
NOTE: User should check error code if null
objects are permitted in the queue. */
void * pqRemoveMax(PQueue w);
/* This function returns the number of objects
in the PQueue. */
int pqGetSize(PQueue w);
/* This function uninitializes a queue and frees all
memory associated with it. NOTE: value of PQueue
variable is undefined after this function is
applied, i.e., it should not be used unless
initialized again using queueInit. */
void pqFree(PQueue w);


//Performance requirements are that pqGetSize and pqInsert have O(1) complexity.
