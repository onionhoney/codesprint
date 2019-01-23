Cases=input()
Cases=int(Cases)
for i in range(Cases):
    keys=[]
    lines={}
    array = [int(x) for x in input().split()]
    rooms=array[0]
    passages=array[1]
    add=array[2]
    for yee in range(passages):
        temp= [int(x) for x in input().split()]
        lines[temp[0]]=temp[1]
    for key in lines:
        keys.append(key)

    comps=[]
    disc={}
    for key in lines:
        visited=[]
        if key not in disc:
            visited.append(key)
        for i in visited:
            if lines[i] in lines:
                visited.append(lines[i])
                disc[lines[i]]=True
        comps.append(len(visited)+1)
    comps.sort(reverse=True)
    maxx=0
    for i in range(add+1-len(comps)):
        comps.append(1)
    print(comps)
    for i in range(add+1):
        maxx=maxx+comps[i]
    comps=comps[add+1:]
    other=0
    for s in comps:
        toadd=(s)*(s-1)/2
        other=other+toadd
    connected=int(maxx*(maxx-1)/2+other)
    print(connected)
