System-Measurement-Project
==========================

UCSD CSE 221 Project

CPU, Scheduling, and OS Services

1. Measurement overhead.

2. Procedure call overhead.

3. System call overhead.

4. Task creation time.

5. Context switch time.

Memory

1. RAM access time.

2. RAM bandwidth.

3. Page fault service time. 


Network

1. Round trip time. Compare with the time to perform a ping (ICMP requests are handled at kernel level).

  rtt_client.c: argv[1] would be the IP address of the server.
  
  rtt_server.c: No arguments needed.
  
2. Peak bandwidth.

  peakbandwidth_client.c: argv[1] would be the IP address of the server.
  
  peakbandwidth_server.c: No arguments needed.
  
3. Connection overhead: Report setup and tear-down.

  connection_client.c: argv[1] would be the IP address of the server.
  
  connection_server.c: No arguments needed.

File System

1. Size of file cache.

2. File read time.

3. Remote file read time.

4. Contention.
