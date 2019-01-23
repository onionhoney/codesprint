from collections import defaultdict, deque

def findConnected(n, d):
    result = []
    unvisited = set(range(1, n+1))
    while unvisited:
        n = unvisited.pop()
        group = {n}
        queue = deque()
        queue.append(n)
        while queue:
            curr = queue.popleft()
            neighbors = d[curr]
            unvisited -= neighbors
            queue.extend(neighbors - group)
            group = group.union(neighbors)
        result.append(group)
    return result


def solve():
    n, l, k = map(int, input().split())
    d = defaultdict(set)
    for _ in range(l):
        a, b = map(int, input().split())
        d[a].add(b)
        d[b].add(a)
    components = findConnected(n, d)
    components.sort(key=len, reverse=True)
    connections = 0
    for comp in components:
        connections += sum(range(len(comp)))
    for _ in range(min(len(components) - 1, k)):
        connections += len(components[0]) * len(components[1])
        temp = components.pop(0)
        components[0] = components[0].union(temp)
    print(connections)
    


c = int(input())
while (c):
    solve()
    c -= 1
