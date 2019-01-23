Cases=input()
Cases=int(Cases)
for i in range(Cases):
    jumps=input()
    jumps=int(jumps)
    options=input()
    CS31= [int(x) for x in input().split()]
    CS32= [int(x) for x in input().split()]
    maxx=0
    for i in CS31:
        for j in CS32:
            testNum=i+j
            if testNum <= jumps and testNum >= maxx:
                maxx=testNum
    print(maxx)
