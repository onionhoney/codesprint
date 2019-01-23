import bisect

def solve():

	TC = int(input())

	for _ in range(TC):
		n = int(input())
		p, q = map(int, input().split())
		a = list(map(int, input().split()))
		b = list(map(int, input().split()))
		a.sort()
		b.sort()
		best = 0
		for num in a:
			pos = bisect.bisect(b, n-num)
			best = max(best, num + b[pos-1])
		print(best)

	return 

solve()