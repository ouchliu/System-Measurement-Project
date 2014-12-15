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
	if (fd < 0) {
		printf("File error!\n");
		exit(1);
	}

	size_t size = getFileSize(fd);
	blksize_t blockSize = getBlockSize(fd);
	int nBlocks = size/blockSize;

	void* buf = malloc(size);
	unsigned long long start, end, diff;

/*
	start = rdtsc();
	read(fd, buf, size);
	end = rdtsc();
	diff = end - start;
	printf("BLOCKS: %d, FILESIZE: %zd\n", nBlocks, size);
	printf("%llu\n", diff);
	printf("%llu\n", diff/nBlocks);
*/


	int i;
	for (i = 0; i < runs; i++) {
		start = rdtsc();
		read(fd, buf, blockSize);
		end = rdtsc();
	
		diff = end - start;

		printf("%llu\n", diff);
	}

	close(fd);
	free(buf);
}

