#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "rdtscp.h"

int main(int argc, char* argv[]) {
	int runs = get_runs(argc, argv);

	int i;
	for (i = 0; i < runs; i++) {
		pid_t pid = fork();
		if (pid == -1) {
			printf("Fail!\n");
			return 0;
		}
		if (pid == 0) {
			unsigned long long start, end, diff;
			start = rdtsc();
			getpid();
			end = rdtsc();
			diff = end - start;
			printf("%llu\n", diff);
			return 0;
		}

		if (i%7000 == 0) {
			sleep(1);
		}
	}
}