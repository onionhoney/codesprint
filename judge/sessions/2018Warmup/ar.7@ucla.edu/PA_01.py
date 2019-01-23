n = input()

cache = {}
cache[1] = 1
cache[2] = 1
for i in range(3,100001):
    if i in cache:
        continue
    else:
        cache[i] = (cache[i-1]+cache[i-2])%100000007

for i in range(n):
    print cache[input()]
