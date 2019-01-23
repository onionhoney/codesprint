


def main():
    n_locks = int(input())
    for i in range(n_locks):
        for j in range(3):
            output = []
            for k in range(10):
                output.append(int(input()))
            print(str(output.index(1)) + " ")
        print("\n")
'''

def main():
    n_locks = int(input())
    for i in range(n_locks):
        for j in range(3):
            guess = 50
            for k in range(100):
                if (int(input()) == 0):
                    guess = guess/2

'''
if __name__ == '__main__':
    main()