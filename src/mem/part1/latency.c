#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sched.h>
#include "rdtsc.h"
#include "rand.h"

int main(int argc, char* argv[]) {
	//Set cpu affinity
	cpu_set_t set;
	CPU_ZERO(&set);
	CPU_SET(0, &set);
	if (sched_setaffinity(0, sizeof(cpu_set_t), &set) == -1) {
		printf("Affinity Failed!\n");
		exit(1);
	}

	int power;
	int runs;
	if (argc == 3) {
		power = atoi(argv[1]);
		runs = atoi(argv[2]);
	} else {
		printf("Please specify power for array size and run count.\n");
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
		arr_indexes[j] = random_at_most(length);
	}

	//printf("%i\n", power);
	//printf("%i\n", size);
	//printf("%i\n", length);
	//printf("%lu\n", sizeof(int));

	int r = 0;
	for (r = 0; r < runs; r++) {
		//Measure avg read time for array of allocated size.
		unsigned long long start, end, diff;
		start = rdtsc();
		int index;
		int dest = 0;
		int i = 0;
		for (i = 0; i < length; i++) {
			index = arr_indexes[i];
			//printf("%i, %i\n", index, arr[index]);
			dest = arr[index] + dest;
			//dest = arr[i];
		}
		end = rdtsc();
		diff = end - start - 40;

		printf("%llu\n", diff/length);

	}
	free(arr);

}

