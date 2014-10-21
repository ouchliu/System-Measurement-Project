#include <stdio.h>
#include <pthread.h>
#include "rdtsc.h"

void *func(void *threadid) {
	pthread_exit(NULL);
}

int main() {
	unsigned long long clock_total = 0;

	int j;
	int runs = 1000;
	for (j = 0; j < runs; j++) {
		unsigned long long start, end;

		long i;
		pthread_t t;
		start = rdtsc();
		int rc = pthread_create(&t, NULL, func, (void *)i);
		end = rdtsc();
		unsigned long long diff = end - start;
		clock_total = clock_total + diff;
		printf("%lld\n", diff);
	}

	printf("AVG: %lld\n", clock_total/runs);
	pthread_exit(NULL);
}
