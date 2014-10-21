all: cpu1 cpu4process cpu4thread cpu5 pipeoverhead


cpu1:
	gcc -Isrc/lib -o cpu1.out src/cpu/part1/cpu1.c

cpu4process:
	gcc -Isrc/lib -o cpu4process.out src/cpu/part4/cpu4_process.c

cpu4thread:
	gcc -Isrc/lib -o cpu4thread.out -pthread src/cpu/part4/cpu4_thread.c

cpu5:
	gcc -Isrc/lib -o cpu5.out src/cpu/part5/cpu5_simple.c

pipeoverhead:
	gcc -Isrc/lib -o pipeoverhead.out src/cpu/part5/pipe_overhead.c

clean:
	rm *.out
