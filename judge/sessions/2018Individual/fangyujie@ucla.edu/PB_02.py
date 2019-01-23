import sys


input_list = []

def read():
	count = 0
	for line in sys.stdin:
		input_list.append(line.rstrip())
		count += 1
		if count == int(input_list[0])*3 + 1:
			return count

total_number_of_lines = read()


storage = []
list_of_list = []
for i in range(1, total_number_of_lines):
	list_of_list.append(input_list[i])
	if(i%3 == 0):
		storage.append(list_of_list)
		list_of_list = []

result = ""
for i in range(len(storage)):
	temp = storage[i]
	for j in range(len(temp)):
		number = temp[j].split(' ')
		for k in range(len(number)):
			if number[k] == '1':
				if j == len(temp) - 1:
					result = result + str(k)
					print(result)
					result = ""
				else:
					result = result + str(k) + ' '


