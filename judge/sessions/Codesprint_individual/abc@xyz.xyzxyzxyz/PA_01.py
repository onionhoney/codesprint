#!/usr/bin/python3
import sys

n = int(sys.stdin.readline())
for i in range(n):
    m, t = map(int, sys.stdin.readline().split())
    ans = 0
    for j in range(m):
        val, num = map(int, sys.stdin.readline().split())
        while (t > 0 and num > 0) :
            t -= 1
            num -=1
            ans += val

    print(ans)
