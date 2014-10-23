#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "utils.h"
#include "rdtscp.h"

int fd[2];

void *func(void *threadid) {
	unsigned long long start, end, diff;
	read(fd[0], &start, sizeof(start));
	printf("Recieved: %llu\n", start);
	end = rdtsc();
	diff = end - start;
	printf("%llu\n", diff);

	close(fd[0]);
	close(fd[1]);
	pthread_exit(NULL);
}

int main(int argc, char* argv[]) {

	pipe(fd);

	long i;
	pthread_t t;
	int rc = pthread_create(&t, NULL, func, (void *)i);

	unsigned long long start, end, diff;
	start = rdtsc();
	printf("Sent: %llu\n", start);
	write(fd[1], &start, sizeof(start));

	pthread_exit(NULL);
}
