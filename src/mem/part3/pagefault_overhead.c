#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <assert.h>
#include "rdtsc.h"

size_t getFileSize(int fd) {
	struct stat buf;
	fstat(fd, &buf);
	return buf.st_size;
}

int main(int argc, char* argv[]) {
	unsigned long long start, end, diff;

	int fd = open("foo.txt", O_RDONLY);
	size_t size = getFileSize(fd);

	start = rdtsc();
	void* mmappedData = mmap(NULL, 4096, PROT_READ, MAP_PRIVATE, fd, 0);
	end = rdtsc();
	diff = end - start;
	printf("%llu\n", diff);

	assert(mmappedData != NULL);
	//Write the mmapped data to stdout (= FD #1)
	//write(1, mmappedData, size);
	//Cleanup
	int rc = munmap(mmappedData, size);
	assert(rc == 0);

	close(fd);
}

