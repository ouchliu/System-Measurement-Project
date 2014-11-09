#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "rdtsc.h"

int main(int argc, char* argv[]) {
	int power;
	if (argc == 2) {
		power = atoi(argv[1]);
	} else {
		printf("Please specify power for array size.\n");
		exit(1);
	}

	int size = (int)pow(2, power);
	int length = size/sizeof(int);

	int* arr;
	arr = (int*)malloc(size);
	memset(arr, 'a', size);

	//Init random index access.
	srand(time(NULL));
	int* arr_indexes;
	arr_indexes = (int*)malloc(size);
	int j = 0;
	for (j = 0; j < length; j++) {
		arr_indexes[j] = random() % length;
	}

	//printf("%i\n", power);
	//printf("%i\n", size);
	//printf("%i\n", length);
	//printf("%lu\n", sizeof(int));

	int runs = 1000;
	int r = 0;
	for (r = 0; r < runs; r++) {
		//Measure avg read time for array of allocated size.
		unsigned long long start, end, diff;
		start = rdtsc();
		int index;
		int dest;
		int i = 0;
		for (i = 0; i < length; i++) {
			index = arr_indexes[i];
			//printf("%i, %i\n", index, arr[index]);
			dest = arr[index];
			//dest = arr[i];
		}
		end = rdtsc();
		diff = end - start;

		printf("%llu\n", diff/length);

	}
	free(arr);

}

