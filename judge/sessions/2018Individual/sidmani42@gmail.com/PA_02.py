if __name__ == "__main__":
    count = int(input())
    for i in range(count):
        num_jumps = int(input())
        _ = input()
        arr_a = list(map(int, input().split()))
        arr_b = list(map(int, input().split()))
    
        _min = num_jumps
        val = 0
        for a in arr_a:
            for b in arr_b:
                if (num_jumps - (a + b) < _min and a + b <= num_jumps):
                    _min = num_jumps - (a + b)
                    val = a + b

        print(val)