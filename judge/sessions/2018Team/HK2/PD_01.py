import bisect

def solve():

	TC = int(input())

	def printG(g):
		for r in g:
			print(r)

	for _ in range(TC):
		n, k = map(int, input().split())
		a = list(map(int, input().split()))
		picked = [[0 for i in range(k+1)] for j in range(n+1)]
		skipped = [[0 for i in range(k+1)] for j in range(n+1)]
		picked_sel = [[[] for i in range(k+1)] for j in range(n+1)]
		skipped_sel = [[[] for i in range(k+1)] for j in range(n+1)]
		for i in range(1, n+1):
			for j in range(1, min(i, k)+1):
				picked[i][j] = a[i-1] + skipped[i-1][j-1]
				picked_sel[i][j] = skipped_sel[i-1][j-1] + [i]
				skipped[i][j] = max(picked[i-1][j], skipped[i-1][j])
				if picked[i-1][j] > skipped[i-1][j]:
					skipped_sel[i][j] = picked_sel[i-1][j]
				else:
					skipped_sel[i][j] = skipped_sel[i-1][j]
		ans = picked_sel[-1][-1]
		ans = ' '.join(list(map(str, ans)))
		print(ans)

	return 

solve()