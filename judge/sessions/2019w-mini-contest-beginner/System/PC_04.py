def findKid(parent, memo):
    if parent < 1:
        return 1
    if parent not in memo: 
        if parent % 2 == 1:  
            memo[parent]=sum(findKid(x,memo) for x in [parent-1, parent-3])
        else:
            memo[parent]=sum(findKid(x,memo) for x in [parent//2, parent-2, parent-4])
    return memo[parent]

myMemo = {}
def findSmallestParent(kid):
    parent = 1
    while parent<kid:
        if(findKid(parent, myMemo) == kid):
            return parent
        else:
            parent+=1
    return -1
    
num_tests=int(input())
for n in range(num_tests):
    l = input()
    print(findSmallestParent(int(l))