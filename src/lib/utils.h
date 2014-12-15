#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <sys/stat.h> 
#include <fcntl.h>

int get_runs(int argc, char* argv[]) {
	int runs;
	if (argc == 2) {
		runs = atoi(argv[1]);
	} else {
		runs = 1000;
	}
	return runs;
}

size_t getFileSize(int fd) {
	struct stat buf;
	fstat(fd, &buf);
	return buf.st_size;
}


blksize_t getBlockSize(int fd) {
	struct stat buf;
	fstat(fd, &buf);
	return buf.st_blksize;
}

/*
	Source: http://stackoverflow.com/questions/2509679/how-to-generate-a-random-number-from-within-a-range
*/
long random_at_most(long max) {
  unsigned long
    // max <= RAND_MAX < ULONG_MAX, so this is okay.
    num_bins = (unsigned long) max + 1,
    num_rand = (unsigned long) RAND_MAX + 1,
    bin_size = num_rand / num_bins,
    defect   = num_rand % num_bins;

  long x;
  // This is carefully written not to overflow
  while (num_rand - defect <= (unsigned long)(x = random()));

  // Truncated division is intentional
  return x/bin_size;
}

#endif
