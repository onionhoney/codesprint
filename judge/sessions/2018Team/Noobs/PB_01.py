import sys

cases = int(sys.readline())

lines = sys.read().split('\n')

for i in range(cases):
    n, p, q = [int(token) for token in lines[3*i]]
    instability = [int(token) for token in lines[3*i + 1]]
    tilting = [int(token) for token in lines[3*i + 2]]
    
    total = 0
    
    for j in range(n):
        best_i, best_i_index = max([(instability[k], k) for k in range(p)])
        best_t, best_t_index = max([(tilting[k], k) for k in range(q)])
        
        if best_i > best_t:
            total += best_i
            instability[best_i_index] -= 1
            
            idx = min(range(q), key=lambda k: tilting[k] or 1e300)
            tilting[idx] -= 1
        else:
            total += best_t
            tilting[best_t_index] -= 1
            
            idx = min(range(p), key=lambda k: instability[k] or 1e300)
            instability[idx] -= 1
    print(total)
        
        
