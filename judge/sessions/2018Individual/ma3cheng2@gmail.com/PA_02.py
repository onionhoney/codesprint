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
	b.reverse()
	print b

	summm = 0
	for i in a:
		# get maximum 
		for j in b:
			if i + j <= total and i + j > summm:
				summm = i + j
				break
	print summm









