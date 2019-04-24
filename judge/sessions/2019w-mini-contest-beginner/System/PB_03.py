def reorderString(myString):
    return myString[1::2] + myString[::2][::-1]
    
num_tests=int(raw_input())
for n in range(num_tests):
    l = raw_input()
    print(reorderString(l))