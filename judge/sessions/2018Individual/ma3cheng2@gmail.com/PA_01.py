import sys
number = int(sys.stdin.readline())

# return the max sum smaller than total

for num in range(number):
	total = int(sys.stdin.readline())
	p = sys.stdin.readline()
	array_size = list(map(int, p.split()))

	p = sys.stdin.readline()
	a = list(map(int, p.split()))

	p = sys.stdin.readline()
	b = list(map(int, p.split()))

	a = sorted(a)
	b = sorted(b)

	summm = 0
	for i in a:
		for j in b:
			tmp = i + j
			if tmp <= total and summm < tmp:
				summm = tmp
	print summm









