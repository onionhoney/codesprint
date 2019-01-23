import sys
number = int(sys.stdin.readline())

def fac(p):
    a = 0
    b = 1
    if p == 0:
        return 0
    elif p == 1:
        return 1
    else:
        for i in range(p):
            (a, b) = (a + b, a)
        return a % 100000007

for i in range(number):
    num = int(sys.stdin.readline())
    k = fac(num)
    print(k)


