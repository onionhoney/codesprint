import sys

total = int(sys.stdin.readline())

def get_root(uf, i):
	while i != uf[i]:
		i = uf[i]
	return i


def union(uf, size, i, j):
	root_i = get_root(uf, i)
	root_j = get_root(uf, j)
	uf[root_i] = root_j
	size[root_j] = size[root_i] + size[root_j]
	size[root_i] = 0

for num in range(total):
	p = sys.stdin.readline()
	aaa = list(map(int, p.split()))

	n = aaa[0]
	uf = list(range(n))
	size = [1] * n

	for i in range(aaa[1]):
		p = sys.stdin.readline()
		bbb = list(map(int, p.split()))
		union(uf, size, bbb[0] - 1, bbb[1] - 1)



	size = sorted(size)
	size.reverse()


	summm = 0
	tmp = 0

	for i in range(len(size)):

		if i < aaa[2]:
			tmp += size[i]
		elif i == aaa[2]:
			tmp += size[i]
			summm = tmp * (tmp - 1) / 2
		else:
			if size[i] > 0:
				summm += size[i] - 1

	print(summm)





