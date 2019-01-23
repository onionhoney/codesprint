import sys

total = int(sys.stdin.readline ())

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

	for ppppp in range(3):
		if (ppppp == 2 and i != total - 1):
			print(result[ppppp])
		else:
			print(result[ppppp]),
