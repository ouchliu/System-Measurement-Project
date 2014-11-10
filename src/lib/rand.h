#ifndef RAND_H
#define RAND_H

#include <stdlib.h>

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
