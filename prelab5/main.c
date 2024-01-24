#include"prelab5.h"
int main(void)
{
    int ec = -1;
    List * p = initList(&ec);
    printf("Error Code = %d\n", ec);

    for(int i = 0; i<10; i++)
    {
        p = insertAtHead(i, p, &ec);
    }
    int y = 0;
    List * q;
    for(q = p->next; q!=NULL; q = q->next)
    {
        printf("Object[%d] = %d\n",y, q->object);
        y++;
    }

    printf("The object at the 5th element is %d\n", getAtIndex(5, p));
    printf("The size of the list is %d\n", getListLength(p));
    freeList(p);


}