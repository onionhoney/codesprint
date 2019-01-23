def solve():

	TC = int(input())


	for _ in range(TC):
		n1 = list(map(int, input().split()))
		n2 = list(map(int, input().split()))
		n3 = list(map(int, input().split()))
		a1 = n1.index(1)
		a2 = n2.index(1)
		a3 = n3.index(1)
		print(a1, a2, a3)

	return 

solve()