import math, sys

def parseInput(text):
    lines = text.strip().split('\n')
    numCase = int(lines[0])
    cases = [[int(num) for num in line.split(' ')] for line in lines[1:]]
    output = ''
    for caseNum in range(numCase):
        solution = solve(cases[caseNum * 2][0], cases[caseNum * 2][1], cases[caseNum * 2 + 1])
        output += str(solution) + '\n'
    return output

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
            opt1 = opt[(j - 1, l)] if l*2 <= j-1 else 0
            opt2 = opt[(j - 2, l - 1)] + pops[j - 1]
            opt[(j, l)] = max(opt1, opt2)
    return opt[(n, k)]

print(parseInput(sys.stdin.read()))
