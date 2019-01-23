import sys
number = int(sys.stdin.readline())

# return the max sum smaller than total
# a is array
def find_max(a, p):
	i = 0
	j = len(a)
	while (i < j):
		mid = (i + j) / 2
		if (a[mid] < p):
			i = mid + 1
		elif (a[mid] == p):
			return p 
		else:
			j = mid - 1
	return a[i - 1] 


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
		# get maximum 
		k = find_max(b, total - i)
		summm = max(summm, k + i)
	print summm









