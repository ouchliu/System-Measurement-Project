#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include "rdtsc.h"
#include "utils.h"

unsigned long long getReadTime(char* filename, void* buf, size_t size) {
	unsigned long long start, end, diff;

	int fd = open(filename, O_RDONLY);

	start = rdtsc();
	read(fd, buf, size);
	end = rdtsc();

	close(fd);

	diff = end - start;
	return diff;
}

int main(int argc, char** argv) {
	char* filename;
	int runs = 40;
	if (argc == 3) {
		filename = argv[1];
		runs = atoi(argv[2]);
	} else {
		printf("Please enter file name and run count.\n");
		exit(1);
	}

	int fd = open(filename, O_RDONLY);
	if (fd < 0) {
		printf("File error!\n");
		exit(1);
	}

	size_t size = getFileSize(fd);
	close(fd);

	void* buf = malloc(size);
	
	unsigned long long time;

	int i;
	for(i = 0; i < runs; i++) {
		time = getReadTime(filename, buf, size);
		printf("%llu\n", time);
	}
}

