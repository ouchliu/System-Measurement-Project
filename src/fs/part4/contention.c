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
	int n_processes;
	if (argc == 2) {
		n_processes = atoi(argv[1]);
	} else {
		printf("Please supply # of processes.");
		exit(1);
	}
	int pid = 0;
	int index = 0;
	
	//Files map.
	char* files[10];
	files[0] = "/tmp/foobaz1";
	files[1] = "/tmp/foobaz2";
	files[2] = "/tmp/foobaz3";
	files[3] = "/tmp/foobaz4";
	files[4] = "/tmp/foobaz5";
	files[5] = "/tmp/foobaz6";
	files[6] = "/tmp/foobaz7";
	files[7] = "/tmp/foobaz8";
	files[8] = "/tmp/foobaz9";
	files[9] = "/tmp/foobaz10";

	char* filename = files[0];

	//Create n processes and assign each one a unique file.
	int i;
	for (i = 1; i < n_processes; i++) {
		pid = fork();
		if (pid == 0) {
			filename = files[i];
			index = i;
			break;
		}
	}

	//Open file.
	int fd = open(filename, O_RDONLY | O_DIRECT);
	if (fd < 0) {
		printf("File error!\n");
		exit(1);
	}

	//Get file info.
	size_t size = getFileSize(fd);
	blksize_t blockSize = getBlockSize(fd);
	int nBlocks = size/blockSize;

	//Allocate aligned memory.
	void* buf = malloc(size);
	posix_memalign(&buf, 512, size);

	unsigned long long start, end, diff;

	i = 0;
	for (i = 0; i < nBlocks; i++) {
		//Only parent will print out block read time.
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

