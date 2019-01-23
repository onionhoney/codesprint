import math
if __name__ == "__main__":
    count = int(input())
    for i in range(count):
        max_len = list(map(int, input().split()))[1]
        string = input()
        unique = len(set(string))
        char_len = int(math.ceil(math.log(unique, 2)))
        while (char_len > max_len):
            string = string[:-1]
            unique = len(set(string))
            print(unique)
            char_len = int(math.ceil(math.log(unique, 2)))
        if (char_len != 0):
            max_chars = min(math.floor(max_len / char_len) * char_len, len(string))
            print(max_chars)
        else:
            print(min(max_len, len(string)))
