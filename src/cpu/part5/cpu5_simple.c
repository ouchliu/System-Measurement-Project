#include <stdio.h>
#include <unistd.h>
#include "utils.h"
#include "rdtscp.h"

int main(int argc, char* argv[]) {
	int runs = get_runs(argc, argv);

	int i;
	for (i = 0; i < runs; i++) {

		int fd[2];
		pipe(fd);

		int pid = fork();
		if (pid == -1) {
			perror("fork failed!");
			return 1;
		}
		if (pid == 0) { //Child
			unsigned long long start, end, diff;
			read(fd[0], &start, sizeof(start));
			//printf("Recieved: %llu\n", start);
			end = rdtsc();
			//printf("End: %llu\n", end);
			diff = end - start;
			printf("%llu\n", diff);
			return 0;
		} else {
			unsigned long long start, end, diff;
			start = rdtsc();
			//printf("Sent: %llu\n", start);
			write(fd[1], &start, sizeof(start));
		}

		close(fd[0]);
		close(fd[1]);

	}
}
