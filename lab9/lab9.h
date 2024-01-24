#include <stdio.h>
#include <stdlib.h>


void * makeArray(int arraySize, int elementSize);

int getSize(void *array);

typedef struct {
	unsigned long accountNumber;
	float accountWorth;
	int daysActive;
} Client;


// O(log(n))

int searchClients(Client *array, Client *query);

// O(1)

int compareClients(Client *a, Client *b);

void freeArray(void *array);
