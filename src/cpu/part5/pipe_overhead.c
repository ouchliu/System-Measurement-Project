#include <stdio.h>
#include <unistd.h>
#include "utils.h"
#include "rdtscp.h"

int main(int argc, char* argv[]) {
	int runs = get_runs(argc, argv);

	int fd[2];
	pipe(fd);

	int i;
	for (i = 0; i < runs; i++) {
		unsigned long long start, end, diff;
		start = rdtsc();
		write(fd[1], &start, sizeof(start));
		read(fd[0], &start, sizeof(start));
		end = rdtsc();
		diff = end - start;
		printf("%llu\n", diff);
	}

	close(fd[0]);
	close(fd[1]);
}