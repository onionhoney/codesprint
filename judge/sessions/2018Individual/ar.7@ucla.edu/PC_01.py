def update_connections_opt(connections, r1, r2):
    x_y = connections[r1].union(connections[r2])

    connections[r1].update(x_y)
    connections[r2].update(x_y)

    for i in x_y:
        connections[i].update(x_y)
    return connections

c=int(input())
for i in range(c):
    n,l,k = [int(_) for _ in input().split(" ")]
    connections = {i:set([i]) for i in range(1,n+1)}
    for j in range(l):
        a,b = [int(_) for _ in input().split(" ")]
        connections = update_connections_opt(connections, a, b)

    connections_made = 0
    ignore_set = set()
    while connections_made < k:
        ordered = sorted(connections, key=lambda k: len(connections[k]), reverse=True)
        #print(ordered)
        best,next_best = 0,0
        for r in ordered:
            if r in ignore_set:
                continue
            conns = connections[r]
            if len(conns)==n:
                ignore_set.add(r)
                continue

            if not best:
                best=r
            else:
                if r not in connections[best]:
                    next_best=r
            if best and next_best:
                break

        if best and next_best:
            #make connection
            #print(best,next_best)
            connections[best].add(next_best)
            connections[next_best].add(best)
            connections_made+=1
            connections = update_connections_opt(connections, best, next_best)
        else:
            break

    done = set()
    total = 0
    for i,j in connections.items():
        temp = tuple(j)
        #print(temp)
        if temp not in done:
            done.add(temp)
            len_temp = len(temp)
            total+= int(0.5*len_temp*(len_temp-1))

    print(total)


