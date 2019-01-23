import sys
import string

if __name__ == "__main__":
    input = sys.stdin.readlines()
    case = int(input[0])
    for i in range(case):
        input[i * 2 + 1] = list(map(int, input[i * 2 + 1].split()))
        action = input[i * 2 + 1][0]
        before = input[i * 2 + 1][1]
        actions = input[i * 2 + 2]
        h = actions.rfind('H')
        k = 0
        for j in range(h, action + 1):
            if actions[j] == 'L':
                k = k + 1
            elif actions[j] == 'R':
                k = k - 1
        print(int(k))



