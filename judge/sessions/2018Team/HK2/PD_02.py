import bisect

def solve():

	TC = int(input())

	def printG(g):
		for r in g:
			print(r)

	for _ in range(TC):
		n, k = map(int, input().split())
		a = list(map(int, input().split()))
		# Initialize 2D arrays
		picked = [[0 for i in range(k+1)] for j in range(n+1)]
		skipped = [[0 for i in range(k+1)] for j in range(n+1)]
		picked_sel = [[[] for i in range(k+1)] for j in range(n+1)]
		skipped_sel = [[[] for i in range(k+1)] for j in range(n+1)]
		mostTribs = 0
		# Fill out arrays
		for i in range(1, n+1):
			for j in range(1, min(i, k)+1):
				# Select this district
				picked[i][j] = a[i-1] + skipped[i-1][j-1]
				picked_sel[i][j] = skipped_sel[i-1][j-1] + [i]
				# Skip this district
				skipped[i][j] = max(picked[i-1][j], skipped[i-1][j])
				if picked[i-1][j] > skipped[i-1][j]:
					skipped_sel[i][j] = picked_sel[i-1][j]
				else:
					skipped_sel[i][j] = skipped_sel[i-1][j]
		# Best selection with k tributes picked
		for i in range(1, n+1):
			if picked[i][-1] > mostTribs and len(picked_sel[i][-1]) == k:
				ans = picked_sel[i][-1]
				mostTribs = picked[i][-1]
		ans = ' '.join(list(map(str, ans)))
		print(ans)
		# printG(picked_sel)
		# printG(picked)

	return 

solve()