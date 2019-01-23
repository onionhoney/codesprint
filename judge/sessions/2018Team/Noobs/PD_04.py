import math, sys

def solve(n, k, pops):
    # opt((number considered (a_1...a_j), number chosen))
    opt = {}
    for l in range(k + 1):
        opt[(0, l)] = 0
        opt[(-1, l)] = 0
    for j in range(n + 1):
        opt[(j, 0)] = 0
    for l in range(1, k+1):
        j = 2*l-1
        if j > n: continue
        opt[(j, l)] = opt[(j-2, l-1)] + pops[j-1]
        for j in range(2*l, n+1):
            opt1 = opt[(j - 1, l)]
            opt2 = opt[(j - 2, l - 1)] + pops[j - 1]
            opt[(j, l)] = max(opt1, opt2)
    return opt[(n, k)]

case_count = int(sys.stdin.readline())
lines = sys.stdin.read().split('\n')
for i in range(case_count):
    n, k = [int(token) for token in lines[2*i].split()]
    print(solve(n, k, [int(token) for token in lines[2*i+1].split()]))
