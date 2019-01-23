n = int(input())
for i in range(n):
    l1 = [int(_) for _ in input().split(" ")]
    l2 = [int(_) for _ in input().split(" ")]
    l3 = [int(_) for _ in input().split(" ")]
    print(l1.index(1), l2.index(1), l3.index(1))
