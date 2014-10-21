#!/usr/bin/env python
import fileinput

total = 0
count = 0
for line in fileinput.input():
	total = total + int(line)
	count = count + 1

print total/count
