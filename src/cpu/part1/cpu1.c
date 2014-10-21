#include <stdio.h>
#include "utils.h"
#include "rdtscp.h"

int main(int argc, char* argv[]) {
	int runs = get_runs(argc, argv);
	printf("Runs: %i\n", runs);

	unsigned long clock_total = 0;

	int i;
	for (i = 0; i < runs; i++) {
		unsigned long long start, end;
		start = rdtsc();
		end = rdtsc();
		unsigned long diff = end - start;
		clock_total = clock_total + diff;
	}

	printf("AVG: %lu\n", clock_total/runs);
}
