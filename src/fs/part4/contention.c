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
	int n_processes = atoi(argv[1]);
	int pid = 0;
	int i = 0;
	int index;

	char* files[10];
	files[0] = "/tmp/foobaz1";
	files[1] = "/tmp/foobaz2";
	files[2] = "/tmp/foobaz3";
	files[3] = "/tmp/foobaz4";
	files[4] = "/tmp/foobaz5";
	files[5] = "/tmp/foobaz6";
	files[6] = "/tmp/foobaz6";
	files[7] = "/tmp/foobaz7";
	files[8] = "/tmp/foobaz8";
	files[9] = "/tmp/foobaz9";

	char* filename;

	for (i = 0; i < n_processes; i++) {
		if (pid == 0) {
			pid = fork();
			filename = files[i];
			index = i;
		}
	}
	
//	if (index == 0)
//	printf("%d %s\n", pid, filename);

	int fd = open(filename, O_RDONLY | O_DIRECT);
	if (fd < 0) {
		printf("File error!\n");
		exit(1);
	}

	size_t size = getFileSize(fd);
	blksize_t blockSize = getBlockSize(fd);
	int nBlocks = size/blockSize;
	void* buf = malloc(size);
	posix_memalign(&buf, blockSize, blockSize);
	unsigned long long start, end, diff;

	posix_fadvise(fd, 0, size, POSIX_FADV_RANDOM);

	i = 0;
	for (i = 0; i < nBlocks; i++) {
		if (index == 0) {
			start = rdtsc();
			read(fd, buf, blockSize);
			end = rdtsc();
			diff = end - start;
			printf("%llu\n", diff);
		} else {
			read(fd, buf, blockSize);
		}
	}
	close(fd);
	free(buf);
}

