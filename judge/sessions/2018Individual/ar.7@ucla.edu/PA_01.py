import itertools

t = int(input())

for i in range(t):
    n = int(input())
    p,q = [int(_) for _ in input().split(" ")]
    cs31 = [int(_) for _ in input().split(" ")]
    cs32 = [int(_) for _ in input().split(" ")]

    cs31 = list(set(cs31))
    cs32 = list(set(cs32))
    max_classes = max(list(sum(list(i)) for i in itertools.product(cs31,cs32) if sum(list(i)) <= n))
    print(max_classes)
