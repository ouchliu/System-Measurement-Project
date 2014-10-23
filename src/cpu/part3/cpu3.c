#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "rdtscp.h"

int main(int argc, char* argv[]) {
	int runs = get_runs(argc, argv);

	int i;
	for (i = 0; i < runs; i++) {
		unsigned long long start, end, diff;
		start = rdtsc();
		getpid();
		end = rdtsc();
		diff = end - start;
		printf("%llu\n", diff);
	}
}