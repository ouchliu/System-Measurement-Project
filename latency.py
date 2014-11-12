from __future__ import print_function
import subprocess
import sys

bits = '64'
n_samples = 10
start = 10
end = 30

if len(sys.argv) >= 2:
	bits = sys.argv[1]
if len(sys.argv) >= 3:
	start = int(sys.argv[2])
if len(sys.argv) >= 4:
	end = int(sys.argv[3])

def getSize(power):
	return int(2**power)

def overhead(bits, size):
	output = ['./latency_overhead{}.out'.format(bits), str(size)]
	o = subprocess.check_output(output).split(',')[0]
	return int(o)

def latency(bits, size):
	output = ['./latency{}.out'.format(bits), str(size)]
	o = subprocess.check_output(output).split(',')[0]
	return int(o)

def avg(samples):
	return float(sum(samples))/float(len(samples))

for power in range(start, end):
	for i in [0, 0.5]:
		subpower = power + i
		size = getSize(subpower)
		overhead_samples = [overhead(64, size) for i in range(n_samples)]
		latency_samples = [latency(64, size) for i in range(n_samples)]

		avg_overhead = avg(overhead_samples)
		avg_latency = avg(latency_samples)
		diff = avg_latency - avg_overhead
		print(size, subpower, diff, sep=',')
