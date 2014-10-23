#include <stdio.h>
#include <pthread.h>
#include "utils.h"
#include "rdtsc.h"

void *func(void *threadid) {
	pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
	int runs = get_runs(argc, argv);

	unsigned long long clock_total = 0;

	int j;
	for (j = 0; j < runs; j++) {
		unsigned long long start, end, diff;

		long i;
		pthread_t t;
		start = rdtsc();
		int rc = pthread_create(&t, NULL, func, (void *)i);
		end = rdtsc();
		diff = end - start;
		clock_total = clock_total + diff;

		//printf("%llu\n", diff);
	}

	printf("AVG: %lld\n", clock_total/runs);
	pthread_exit(NULL);
}
