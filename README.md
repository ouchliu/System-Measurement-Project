System-Measurement-Project
==========================

UCSD CSE 221 Project

You can compile some of the code with the make file.
- 'make cpu' will compile cpu code.
- 'make mem' will compile mem code.
- 'make fs' will compile fs code.

Many experiments return an instance of measured time to standard out.
The avg.py is a script which will average the results from standard out.
- e.g. './cpu1.out 200000 | ./avg.py' will execute cpu1 experiment 1 and return the average result.

How to run CPU
--------------
- Run 'make cpu'
- Measurement overhead: './cpu1.out <# of runs> | ./avg.py'
- Procedure overhead: './cpu2_<# of arugments>.out <# of runs> | ./avg.py'
- Syscall overhead: './cpu3.out <# of runs> | ./avg.py'
- Process creation: './cpu4process.out'
- Thread overhead: './cpu4thread.out'
- Process context switch: './cpu5.out <# of runs> | ./avg.py'
- Process context switch: './cpu5thread.out <# of runs> | ./avg.py'

How to run MEM
--------------
- Run 'make mem'
- RAM Latency: './latency64.out <size of array in bytes>'
  - first value is latency in cycles.
- RAM Bandwidth: './bandwidth.out <size in MB>'
- Pagefault: './pagefault.sh'
  - value above segfault is page fault in cycles.

How to run file cache experiemnt
---------------------
1. First run 'make fs'
2. For file cache experiment, generate input files with 'makeFiles.sh /tmp'
3. File cache: './file_cache.sh'

How to run file read experiment
-------------------------------
1. 'make fs'
2. Pick a directory <dir> to create files in.
3. './makeFilesReads.sh <dir>' will create files in <dir>
4. './file_read_seq.sh <dir>' will run the sequential experiment on <dir>
5. './file_read_random.sh <dir>' will run the random experiment on <dir>

How to run file contention experiment
-------------------------------------
1. 'make fs'
2. './makeFilesContention.sh /tmp' to create files in /tmp dir.
3. './contention.out <# of processes> | ./avg.py' to get result.

How to run Network
-------
1. Round trip time. Compare with the time to perform a ping (ICMP requests are handled at kernel level).

  rtt_client.c: argv[1] would be the IP address of the server.
  
  rtt_server.c: No arguments needed.
  
2. Peak bandwidth. 

  peakbandwidth_client.c: argv[1] would be the IP address of the server.
  
  peakbandwidth_server.c: No arguments needed.
  
3. Connection overhead: Report setup and tear-down.

  connection_client.c: argv[1] would be the IP address of the server.
  
  connection_server.c: No arguments needed.
