#include <unistd.h>
#include <stdio.h>
#include "utils.h"
#include "rdtsc.h"

int main(int argc, char* argv[]) {
	int runs = get_runs(argc, argv);

	unsigned long long clock_total = 0;

	int i;
	for (i = 0; i < runs; i++) {
		unsigned long long start, end, diff;
		start = rdtsc();
		pid_t pid = fork();
		end = rdtsc();
		diff = end - start;

		if (pid == -1) {
			printf("Failed!\n");
			return 0;
		}
		if (pid == 0) { //Child
			return 0;
		} else { //Parent
			clock_total = clock_total + diff;
			//printf("%llu\n", diff);
		}
	}

	//printf("CLOCK_TOTAL: %llu\n", clock_total);
	printf("AVG: %llu\n", clock_total/runs);
}
