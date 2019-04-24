def reorderString(myString):
    return myString[1::2] + myString[::2][::-1]
    
num_tests=int(input())
for n in range(num_tests):
    l = input()
    print(reorderString(l))