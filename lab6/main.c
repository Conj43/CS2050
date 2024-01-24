#include"lab6.h"


int main(void) 
{
	int size = 5;
	int array[] = { 1, 2, 3, 4, 5 };

	Node *list = (void *)-1;
	int ec = makeList(&list);
    printf("Make List Error Code = %d\n", ec);


	   for(int i = 0; i<size; i++)
    {
        insertAtTail(list, array + i);
    }
    int y = 0;
    Node * q;
    for(q = list->next; q!=NULL; q = q->next)
    {
        int *data = q->data;
        printf("Object[%d] = %d\n",y, *data);
        y++;
    }
    int * obj = getAtIndex(list, 3);
    printf("The data at the 3rd element is %d\n", *obj);
    printf("The size of the list is %d\n", getSize(list));
    int * ear = removeFromHead(list);
    printf("We removed an item from the head and its data was: %d\n", *ear);
    printf("Now the list looks like this: \n");
    Node * r;
    int z = 0;
    for(r = list->next; r!=NULL; r = r->next)
    {
        int *data = r->data;
        printf("Object[%d] = %d\n",z, *data);
        z++;
    }
    freeList(&list);


}
