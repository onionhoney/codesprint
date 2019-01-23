import sys
import numpy as np




if __name__ == "__main__":
    input = sys.stdin.readlines()
    for i in range(len(input)):
        input[i] = list(map(int, input[i].split()))
    case = input[0][0]
    jump = np.zeros(case)
    for i in range(case):
        jump = input[4 * i + 1]
        option = input[4 * i + 2]
        class1 = input[4 * i + 3]
        class2 = input[4 * i + 4]
        sub2 = np.zeros((option[0], option[1]))
        sub3 = np.zeros((option[0], option[1]))
        #print(sub2.size)
        for j in range(option[0]):
            sub = jump[0] - class1[j]
            for k in range(option[1]):
                sub2[j][k] = int(abs(sub - class2[k]))
                sub3[j][k] = int(sub - class2[k])
        index = np.where(sub2 == sub2.min())
        #print(index)
        print(int(jump - sub3[index][0]))






