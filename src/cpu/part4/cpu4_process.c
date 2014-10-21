#include <unistd.h>
#include <stdio.h>
#include "utils.h"
#include "rdtsc.h"

int main(int argc, char* argv[]) {
	int runs = get_runs(argc, argv);
	printf("Runs: %i\n", runs);

	unsigned long long clock_total = 0;

	int i;
	for (i = 0; i < runs; i++) {
		unsigned long long start, end;
		start = rdtsc();
		pid_t pid = fork();
		end = rdtsc();
		unsigned long long diff = end - start;

		if (pid == 0) {
			//Child
			return end-start;
		} else {
			//Parent
			clock_total = clock_total + diff;
		}
	}

	printf("CLOCK_TOTAL: %llu\n", clock_total);
	printf("AVG: %llu\n", clock_total/runs);
}
