#ifndef RUNS_H
#define RUNS_H

int get_runs(int argc, char* argv[]) {
	int runs;
	if (argc == 2) {
		runs = atoi(argv[1]);
	} else {
		runs = 1000;
	}
	return runs;
}

#endif
