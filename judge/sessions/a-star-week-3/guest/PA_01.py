n = int(input())

def fib(x):
    p, q = 0, 1
    for i in range(x):
        q, p = p + q, q
        q %= 100000007
        p %= 100000007
    return p

for i in range(n):
    x = int(input())
    print(fib(x))