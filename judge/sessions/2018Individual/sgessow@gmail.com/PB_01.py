Cases=input()
Cases=int(Cases)
for i in range(Cases):
    Num1= [int(x) for x in input().split()]
    Num2= [int(x) for x in input().split()]
    Num3= [int(x) for x in input().split()]
    count=0
    ans=[]
    for i in Num1:
        if i==1:
            ans.append(count)
        count=count+1
    count=0
    for i in Num2:
        if i==1:
            ans.append(count)
        count=count+1
    count=0
    for i in Num3:
        if i==1:
            ans.append(count)
        count=count+1
print(ans[0],ans[1],ans[2])
