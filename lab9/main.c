#include "lab9.h"

int main() {

	{
		size_t size = 1000000;
		int numTests = 40;

		Client *array = makeArray(size, sizeof(Client));
		if(getSize(array) != size) {
			fprintf(stderr, "ERROR: getSize() returned an unexpected value\n");
		} else {
			puts("ArraySize() returned the expected value");
		}

		// filling the array
		for(size_t i = 0; i < size; ++i) {
			array[i].accountWorth = i;
		}

		void *cursor;
		size_t index, result;
		srand(size);

		puts("Performing search");
		while(numTests-- > 0) {
			index = rand() % size;
			cursor = array + index;
			result = searchClients(array, cursor);
			if(result != index) {
				fprintf(stderr, "ERROR: search returned incorrect index { ");
				fprintf(stderr, "Expected index %zu, got index %zu }\n", index, result);
			}
		}
		Client temp = { 0, -1, 0 };
		if(searchClients(array, &temp) != -1) {
			fprintf(stderr, "ERROR: search returned success on invalid query");
		} else {
			puts("Search successfully returned error on invalid query");
		}
		puts("Freeing array");
		freeArray(array);
	}

	puts("Search done\n");
}