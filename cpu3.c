#include <unistd.h>
#include <stdio.h>
#include "rdtsc.h"

int main(int argc, char* argv[]) {
	int runs;
	if (argc == 2) {
		runs = atoi(argv[1]);
	} else {
		printf("Expecting run count\n");
	}

	unsigned long long start, end;

	int i;
	unsigned long long clock_total = 0;
	for (i = 0; i < runs; i++) {
		start = rdtsc();
		pid_t pid = fork();
		end = rdtsc();
		unsigned long long diff = end - start;

		if (pid == 0) {
			//printf("Child Process\n");
			return end-start;
		} else {
			//printf("Parent Process\n");
			printf("%llu\n", diff);
			clock_total = clock_total + diff;
		}
	}

	printf("CLOCK_TOTAL: %llu\n", clock_total);
	printf("AVG: %llu\n", clock_total/runs);
}
