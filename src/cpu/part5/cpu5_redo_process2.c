#include <stdio.h>
#include <unistd.h>
#include "rdtsc.h"
#include "utils.h"

int main(int argc, char* argv[]) {
	int runs;
	if (argc == 2) {
		runs = atoi(argv[1]);
	} else {
		printf("Please specify run count.\n");
		exit(1);
	}

	//Create pipes. One for receving start times. One for responding back.
	int receive[2];
	int response[2];
	pipe(receive);
	pipe(response);

	unsigned long long start, end, diff;

	int pid = fork();
	if (pid == -1) {
		perror("fork failed!");
		return 1;
	}
	if (pid == 0) {
		//Child process will recieve start times from parent and print context switch times.
		int i;
		for (i = 0; i < runs; i++) {
			//Wait for parent to send child process the start time.
			read(receive[0], &start, sizeof(start));

			//print time difference
			end = rdtsc();
			diff = end - start;
			printf("%llu\n", diff);

			//Respond to parent to signal child is ready to receive another start time.
			write(response[1], &start, sizeof(start));
		}

		exit(0);
	} else {
		//Parent process will send start times to child process.

		int i;
		for (i = 0; i < runs; i++) {
			//Send child process the start time.
			start = rdtsc();
			//printf("Sent: %llu\n", start);
			write(receive[1], &start, sizeof(start));

			//Wait for signal from child before sending another one.
			read(response[0], &start, sizeof(start));
		}
		
	}

	close(receive[0]);
	close(receive[1]);
	close(response[0]);
	close(response[1]);
}

