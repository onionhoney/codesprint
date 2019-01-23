import sys

fib_table = [1,1]

def fib(num):
	result = 0
	if num < len(fib_table):
		return fib_table[num-1]
	else:
		for i in range(len(fib_table),num):
			fib_table.append(fib_table[i-2]+fib_table[i-1])
		return fib_table[num-1]

first_line = 1
for line in sys.stdin:
	if first_line:
		first_line = 0
	else:
		fib_num = fib(int(line.strip('\n')))
		print(fib_num%100000007)
