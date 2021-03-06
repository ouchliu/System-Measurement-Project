#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long timestamp;

static __inline__ timestamp rdtsc (void) {
    unsigned a, d;
    __asm__ __volatile__("rdtscp": "=a" (a), "=d" (d) );
    return (((timestamp)a) | (((timestamp)d) << 32));
}

int main(int argc, char* argv[]) {
    int loops = atoi(argv[1]);
    timestamp start, end;
    start = rdtsc();
    volatile int i;
    for (i = 0; i < loops; ++i) {
    }
    end = rdtsc();
    printf ("delta t = %llu\n", end - start);
}

