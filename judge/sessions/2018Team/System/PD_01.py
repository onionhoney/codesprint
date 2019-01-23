import math
import sys

sys.setrecursionlimit(10000000)

def hunger_games(n,k,pop,dp):
    if(n<=-1):
        if(k==0):
            return 0,[]
        else:
            return -math.inf,[]
    else:
        if((n,k) in dp):
            return dp[(n,k)]
        elif(k==0):
            return 0,[]
        elif(n//2+1 < k):
            return -math.inf,[]
        else:
            a,a_path=hunger_games(n-1,k,pop,dp)
            b,b_path=hunger_games(n-2,k-1,pop,dp)
            b2=b+pop[n]
            b2_path=[n]+b_path
            max_val=max(a,b2)
            best_path = a_path if a>b2 else b2_path
            dp[(n,k)] = max_val,best_path
            return max_val,best_path

def hunger_games_helper(n,k,pop):
    val,path=hunger_games(n-1,k,pop,{})
    path=path[::-1]
    for p in path:
        print(p+1,end=' ')
    print()

tests=int(input())
for t in range(tests):
    n,k = map(int, input().split())
    pop=list(map(int, input().split()))
    hunger_games_helper(n,k,pop)
