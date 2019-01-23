import sys



if __name__ == "__main__":
    input = sys.stdin.readlines()
    for i in range(len(input)):
        input[i] = list(map(int, input[i].split()))

    lock_num = input[0][0]
    lock = [0]*3
    for i in range(lock_num):
        k = 0
        for j in input[i * 3 + 1]:
            if(j == 1):
                lock[0] = k
                break
            k = k + 1

        for j in input[i * 3 + 2]:
            if (j == 1):
                lock[1] = k
                break
            k = k + 1

        for j in input[i * 3 + 3]:
            if (j == 1):
                lock[2] = k
                break
            k = k + 1

        for n in lock:
            print(int(n))