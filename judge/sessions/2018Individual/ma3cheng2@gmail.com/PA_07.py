import sys

total = int(sys.stdin.readline())


result = []

for i in range(total):
	for j in range(3):
		p = sys.stdin.readline()
		aaa = list(map(int, p.split()))
		s = 0
		for kkk in aaa:
			if kkk == 0:
				s += 1
		result.append(s)
	for pppp in result:
		print(pppp), 
	if (i != total - 1):
		print("\n")
