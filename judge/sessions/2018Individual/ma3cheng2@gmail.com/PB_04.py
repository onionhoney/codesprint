import sys

total = int(sys.stdin.readline())

for i in range(total):
	result = []

	for j in range(3):
		p = sys.stdin.readline()
		aaa = list(map(int, p.split()))
		s = 0
		for kkk in aaa:
			if kkk == 0:
				s += 1
		result.append(s)

	for a in range(3):
		if (a == 2 and i != total - 1):
			print(result[a])
		else:
			print(result[a]),
