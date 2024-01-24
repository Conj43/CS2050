#include"lab7.h"
int main(void)
{
    Stack p;
    p = initStack();
    int array[] = {6, 98, 23, 54, 7, 98, 34, 23, 56, 4};
    //fill queue
    int ec;

    for(int i = 0; i<10; i++)
    {
        ec = pushStack(p, array+i);
        printf("EC[%d] = %d\n",i,ec );
    }

    printf("size of stack is: %d\n", getSize(p));

    int y = 0;
    for(int i = 0; i<10; i++)
    {
        int * data = (int*)getAtIndex(p, y);
        printf("stack[%d] = %d\n", i, *data);
        y++;
    }

    printf("size of queue is: %d\n", getSize(p));

    for(int i = 0; i<5; i++)
    {
        int * data = (int*)popStack(p);
        printf("i removed an item from your stack. its data was: %d\n", *data);
        printf("your stack now has %d elements\n", getSize(p));
    }
    printf("\n");
    int * data = (int*)peekStack(p);
    printf("the item at the top of your stack is now %d\n", *data);
    data = popStack(p);
    data = peekStack(p);
    printf("the item at the top of your stack is now %d\n", *data);
    data = (int*)getAtIndex(p, 3);
    printf("should be NULL %d\n", *data);

    freeStack(p);
}