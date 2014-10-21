#include <stdio.h>
#include <unistd.h>
#include "utils.h"
#include "rdtscp.h"

int main(int argc, char* argv[]) {
	int runs = get_runs(argc, argv);

	int fd[2];
	pipe(fd);

	int pid = fork();
	if (pid == -1) {
		perror("fork failed!");
		return 1;
	}
	if (pid == 0) { //Child
		/*
		unsigned long long start;
		read(fd[0], &start, sizeof(start));
		unsigned long long end = rdtsc();
		unsigned long long diff = end - start;
		printf("%llu\n", diff);
		*/
		int count = 0;
		while (count < runs) {
			unsigned long long start, end, diff;
			start = 0;
			//Signal the parent that child is ready to read.
			write(fd[1], &start, sizeof(start));

			read(fd[0], &start, sizeof(start));
			printf("Recieved: %llu\n", start);
			end = rdtsc();
			diff = end - start;
			//printf("%llu\n", diff);
			
			count++;
		}
	} else {
		int count = 0;
		while (count < runs) {
			unsigned long long start, end, diff;
			//#wait for signal from child.
			read(fd[0], &start, sizeof(start));

			start = rdtsc();
			printf("Sent: %llu\n", start);
			write(fd[1], &start, sizeof(start));

			count++;
		}
	}

	close(fd[0]);
	close(fd[1]);
}
