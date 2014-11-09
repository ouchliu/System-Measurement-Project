#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "rdtscp.h"
#include <time.h>

int main(int argc, char* argv[]) {
	int runs = get_runs(argc, argv);

	int i;
	for (i = 0; i < runs; i++) {
		unsigned long long start, end, diff;
		time_t t;
		start = rdtsc();
		time(&t);
		end = rdtsc();
		diff = end - start;
		printf("%llu\n", diff);
	}
}
