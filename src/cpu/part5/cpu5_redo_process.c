#include <stdio.h>
#include <unistd.h>
#include "rdtsc.h"
#include "utils.h"

int main(int argc, char* argv[]) {
	//Create pipes
	int fd[2];
	pipe(fd);

	unsigned long long start, end, diff;

	int pid = fork();
	if (pid == -1) {
		perror("fork failed!");
		return 1;
	}
	if (pid == 0) { //Child process
		//Wait for parent to send child process the start time.
		read(fd[0], &start, sizeof(start));
		end = rdtsc();
		
		//print time difference
		diff = end - start;
		printf("%llu\n", diff);
		exit(0);
	} else {//Parent process

		//Send child process the start time.
		start = rdtsc();
		printf("Sent: %llu\n", start);
		write(fd[1], &start, sizeof(start));
	}

	close(fd[0]);
	close(fd[1]);
}

