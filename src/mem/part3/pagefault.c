#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <assert.h>
#include "rdtsc.h"
#include "utils.h"

int main(int argc, char* argv[]) {
	char* filename;
	if (argc == 2) {
		filename = argv[1];
	} else {
		printf("Please specify input file.");
		exit(1);
	}

	//Open file.
	int fd = open(filename, O_RDONLY | O_DIRECT);
	size_t size = getFileSize(fd);

	int pageSize = 4096;

	unsigned long long start, end, diff;

	//Pagefault with mmap data and print time.
	start = rdtsc();
	void* mmappedData = mmap(NULL, pageSize, PROT_READ, MAP_PRIVATE | MAP_POPULATE, fd, 0);
	end = rdtsc();
	diff = end - start;
	printf("%llu\n", diff);

	assert(mmappedData != NULL);

	//Cleanup
	int rc = munmap(mmappedData, pageSize);
	assert(rc == 0);

	close(fd);
}

