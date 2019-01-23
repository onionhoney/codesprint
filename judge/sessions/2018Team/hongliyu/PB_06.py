import sys

total = int(sys.stdin.readline())

def get_min(a):
	l = len(a) - 1
	while l >= 0:
		if a[l] > 0:
			return l
		l -= 1
	return -1

for _ in range(total):
	p = sys.stdin.readline()
	a = list(map(int, p.split()))
	times = a[0]

	p = sys.stdin.readline()
	a = list(map(int, p.split()))

	if len(a) == 0:
		continue

	p = sys.stdin.readline()
	b = list(map(int, p.split()))

	if len(b) == 0:
		continue
	
	result = 0

	for _ in range(times):
		a = sorted(a, reverse=True)
		b = sorted(b, reverse=True)

		if a[0] == 0 or b[0] == 0:
			continue

		if (a[0] > b[0]):
			k = get_min(b)
			if (k == -1):
				continue
			result += a[0]
			a[0] -= 1		
			b[k] -= 1
		elif (b[0] < a[0]):
			k = get_min(a)
			if (k == -1):
				continue
			result += b[0]
			b[0] -= 1
			a[k] -= 1
		else:
			ka = get_min(a)
			kb = get_min(b)
			if (a[ka] > b[kb]):
				k = get_min(a)
				if (k == -1):
					continue
				result += b[0]
				b[0] -= 1
				a[k] -= 1
			else:
				k = get_min(b)
				if (k == -1):
					continue
				result += a[0]
				a[0] -= 1		
				b[k] -= 1
	print(result)




















