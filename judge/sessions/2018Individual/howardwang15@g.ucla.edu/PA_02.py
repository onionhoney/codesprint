
def get_input():
    return int(input())

def main():
    test_cases = get_input()
    for case in range(test_cases):
        jumps = get_input()
        cs31_options = get_input()
        cs32_options = get_input()
        cs31 = []
        cs32 = []
        for i in range(cs31_options):
            cs31.append(get_input())
        for i in range(cs32_options):
            cs32.append(get_input())
        max = 0
        for i in range(len(cs31)):
            for j in range(len(cs32)):
                sum = cs31[i] + cs32[j]
                if sum > max and sum <= jumps:
                    max = sum
        print(str(max) + "\n")

if __name__ == '__main__':
    main()