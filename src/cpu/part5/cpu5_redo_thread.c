#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "utils.h"
#include "rdtscp.h"

#define RUNS 1000

int fd[2];
int response[2];

//This thread recieves start times and prints out context switch times.
void *func1(void *runs) {
	int* r = (int *)runs;

	unsigned long long start, end, diff;

	int i;
	for (i = 0; i < *r; i++) {
		//Read start time.
		read(fd[0], &start, sizeof(start));

		//Print out time of context switch
		end = rdtsc();
		diff = end - start;
		printf("%llu\n", diff);

		//Send response to signal thread is ready.
		write(response[1], &start, sizeof(start));
	}

	pthread_exit(NULL);
}

//This thread sends start times to the other thread.
void *func2(void *runs) {
	int* r = (int *)runs;

	unsigned long long start, end, diff;
	int i;
	for (i = 0; i < *r; i++) {
		//Get start time
		start = rdtsc();
		
		//Write start time to thread and wait for response.
		write(fd[1], &start, sizeof(start));

		read(response[0], &start, sizeof(start));
	}

	pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
	int runs;
	if (argc == 2) {
		runs = atoi(argv[1]);
	} else {
		printf("Please specify run count.\n");
		exit(1);
	}

	//Allocate pipes in global memory.
	pipe(fd);
	pipe(response);

	long id = 0;
	pthread_t t1;
	pthread_t t2;
	pthread_create(&t1, NULL, func1, (void *)&runs);
	pthread_create(&t2, NULL, func2, (void *)&runs);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	close(fd[0]);
	close(fd[1]);
}
