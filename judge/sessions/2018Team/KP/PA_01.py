if __name__ == "__main__":
    count = int(input())
    for i in range(count):
        missed = list(map(int, input().split()))[1]
        result = list(input())

        aim = 0

        counter = 0
        prev = ''
        for letter in result:
          if (letter == prev):
            counter += 1
          else:
            counter = 1

          if (counter == missed):
            if (letter == 'L'): 
              aim += 1
            if (letter == 'R'):
              aim -= 1
            counter = 0
          
          prev = letter
        print(aim)

