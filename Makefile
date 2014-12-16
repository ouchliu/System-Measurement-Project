all: fs

cpu: cpu1 cpu2 cpu3 cpu4process cpu4thread cpu5 pipeoverhead

mem: latency bandwidth pagefault latency_overhead pagefault_overhead

network:
	gcc -std=c99 src/network/rtt_client.c -o rtt_client.out
	gcc -std=c99 src/network/rtt_server.c -o rtt_server.out
	gcc -std=c99 src/network/peakbandwidth_client.c -o peakbandwidth_client.out
	gcc -std=c99 src/network/peakbandwidth_server.c -o peakbandwidth_server.out
	gcc -std=c99 src/network/connection_client.c -o connection_client.out
	gcc -std=c99 src/network/connection_server.c -o connection_server.out

fs: file_cache file_read contention

misc: latency_overhead

cpu1:
	gcc -Isrc/lib -o cpu1.out src/cpu/part1/cpu1.c

cpu2:
	gcc -Isrc/lib -w -o cpu2_0.out src/cpu/part2/pco0.c
	gcc -Isrc/lib -w -o cpu2_1.out src/cpu/part2/pco1.c
	gcc -Isrc/lib -w -o cpu2_2.out src/cpu/part2/pco2.c
	gcc -Isrc/lib -w -o cpu2_3.out src/cpu/part2/pco3.c
	gcc -Isrc/lib -w -o cpu2_4.out src/cpu/part2/pco4.c
	gcc -Isrc/lib -w -o cpu2_5.out src/cpu/part2/pco5.c
	gcc -Isrc/lib -w -o cpu2_6.out src/cpu/part2/pco6.c
	gcc -Isrc/lib -w -o cpu2_7.out src/cpu/part2/pco7.c

cpu3:
	gcc -Isrc/lib -o cpu3.out src/cpu/part3/cpu3_fork.c

cpu4process:
	gcc -Isrc/lib -o cpu4process.out src/cpu/part4/cpu4_process.c

cpu4thread:
	gcc -Isrc/lib -o cpu4thread.out -pthread src/cpu/part4/cpu4_thread.c

cpu5:
	#gcc -Isrc/lib -o cpu5.out src/cpu/part5/cpu5_simple.c
	#gcc -Isrc/lib -pthread -o cpu5thread.out src/cpu/part5/cpu5_simple_thread.c
	gcc -Isrc/lib -o cpu5.out src/cpu/part5/cpu5_redo_process2.c
	gcc -Isrc/lib -pthread -o cpu5thread.out src/cpu/part5/cpu5_redo_thread.c

pipeoverhead:
	gcc -Isrc/lib -o pipeoverhead.out src/cpu/part5/pipe_overhead.c

latency:
	gcc -Isrc/lib -lm -o latency8.out src/mem/part1/latency8.c
	gcc -Isrc/lib -lm -o latency16.out src/mem/part1/latency16.c
	gcc -Isrc/lib -lm -o latency32.out src/mem/part1/latency32.c
	gcc -Isrc/lib -lm -o latency64.out src/mem/part1/latency64.c

latency_overhead:
	gcc -Isrc/lib -lm -o latency_overhead8.out src/mem/part1/latency_overhead8.c
	gcc -Isrc/lib -lm -o latency_overhead16.out src/mem/part1/latency_overhead16.c
	gcc -Isrc/lib -lm -o latency_overhead32.out src/mem/part1/latency_overhead32.c
	gcc -Isrc/lib -lm -o latency_overhead64.out src/mem/part1/latency_overhead64.c

bandwidth:
	gcc -Isrc/lib -o bandwidth.out src/mem/part2/bandwidth.c

pagefault:
	gcc -Isrc/lib -o pagefault.out src/mem/part3/pagefault.c

pagefault_overhead:
	gcc -Isrc/lib -o pagefault_overhead.out src/mem/part3/pagefault_overhead.c

file_cache:
	gcc -Isrc/lib -o file_cache.out src/fs/part1/file_cache.c

file_read:
	gcc -Isrc/lib -o file_read_seq.out src/fs/part2/file_read_seq.c
	gcc -Isrc/lib -o file_read_random.out src/fs/part2/file_read_random.c

contention:
	gcc -Isrc/lib -o contention.out src/fs/part4/contention.c

clean:
	rm *.out
