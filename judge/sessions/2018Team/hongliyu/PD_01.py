import sys

total = int(sys.stdin.readline())

def dp(mat, value, chose, i, j):
	if i < 0 or j < 0:
		return 0
	if mat[i][j] != -1:
		return mat[i][j]
	else:
		if j >= int((i + 1) / 2):
			mat[i][j] = dp(mat, value, chose, i - 2, j - 1) + value[i]
			chose[i][j] = True
			return mat[i][j]
		elif j >= 0:
			a = dp(mat, value, chose, i - 2, j - 1) + value[i]
			b = dp(mat, value, chose, i - 1, j)
			if (a > b):
				mat[i][j] = a
				chose[i][j] = True
			else:
				mat[i][j] = b
			return mat[i][j]
		else:
			mat[i][j] = dp(mat, value, chose, i - 1, j)
			return mat[i][j]



for num in range(total):
	p = sys.stdin.readline()
	a = list(map(int, p.split()))

	h = a[0]
	w = a[1]

	p = sys.stdin.readline()
	value = list(map(int, p.split()))

	mat = [[-1 for x in range(w + 1)] for y in range(h + 1)] 

	chose = [[False for x in range(w + 1)] for y in range(h + 1)] 

	dp(mat, value, chose, h - 1, w - 1)

	result = []
	i = h - 1
	j = w - 1

	print(mat[i][j])











