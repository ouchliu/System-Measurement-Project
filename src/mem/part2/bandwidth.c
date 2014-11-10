#include <sys/time.h>
#include <time.h>
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef unsigned long long tick;
static __inline__ tick gettick (void) {
    unsigned a, d;
    __asm__ __volatile__("rdtsc": "=a" (a), "=d" (d) );
    return (((tick)a) | (((tick)d) << 32));
}

//typedef char testtype; 
/* typedef int testtype; */
/* typedef long long testtype; */
typedef __int128_t testtype;

int main(int argc, char* argv[]) {
	int input;
	printf("\n");
	if (argc <= 1) {
		printf("Please give a input(MB)");
		exit(0);
	} else {
		input = atoi(argv[1]);
		if (input <= 0) {
			printf("Invalid count.\n");
			exit(0);
		}
	}
	
	long long size = input * 1024 * 1024;
	long long count = size / sizeof (testtype);
	testtype tmp;
	testtype *array = (testtype*) malloc (size);
	memset (array, 42, size);
	
	testtype *p = array;
	testtype *end = array + count;
	tick ts, te;
	
	ts = gettick();
	do {
		tmp ^= *p;
	} while (++p < end);
	te = gettick();
	printf ("delta t = %llu\nRAM read bandwidth = %f MB/s\n", te-ts, input/((double)(te-ts) / 3e9));
	free (array);
	return (int) tmp;
}
