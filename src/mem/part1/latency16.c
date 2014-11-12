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

	int size = 4096;
	int runs = 100000;

	if (argc == 2) {
		size = atoi(argv[1]);
	} else {
	}

	//Make array
	short* arr = (short*)malloc(size);
	memset(arr, 1234, size);
	int n_items = size/sizeof(short);
	short item;

	//Measure latency
	unsigned long long start, end, diff;
	start = rdtsc();
	int i;
	for (i = 0; i < runs; i++) {
		int rand = random_at_most(n_items - 1);
		item = arr[rand];
	}
	end = rdtsc();
	diff = end - start;
	printf("%llu,%i,%i,%i\n", diff/runs, size, n_items, i);
	
	free(arr);
}
