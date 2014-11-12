import subprocess

n = 5
s = [int(subprocess.check_output(['./pagefault.out'])) for i in range(n)]
o = [int(subprocess.check_output(['./pagefault_overhead.out'])) for i in range(n)]

def avg(l):
	return float(sum(l))/float(len(l))

print avg(s) - avg(o)
