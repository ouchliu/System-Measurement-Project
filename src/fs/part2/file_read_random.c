#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include "rdtsc.h"
#include "utils.h"

int main(int argc, char* argv[]) {
	char* filename;
	int runs;
	if (argc == 3) {
		filename = argv[1];
		runs = atoi(argv[2]);
	} else {
		printf("Please enter file name.\n");
		exit(1);
	}

	int fd = open(filename, O_RDONLY | O_DIRECT);

	size_t size = getFileSize(fd);
	blksize_t blockSize = getBlockSize(fd);

	void* buf = malloc(size);
	unsigned long long start, end, diff;

	int i;
	for (i = 0; i < runs; i++) {
		long offset = random_at_most(size - blockSize);

		start = rdtsc();
		off_t r = lseek(fd, offset, SEEK_SET);
		read(fd, buf, blockSize);
		end = rdtsc();
	
		diff = end - start;
		//printf("%zd\n", r);
		//printf("%zd\n", random_offset);
		printf("%llu\n", diff);
	}

	close(fd);
	free(buf);
}

