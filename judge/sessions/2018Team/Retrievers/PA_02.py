import sys

input_list = []

def read():
	count = 0
	for line in sys.stdin:
		input_list.append(line.rstrip())
		count += 1
		if count == int(input_list[0])*2 + 1:
			return count


total_number_of_lines = read()

storage = []
list_of_list = []
for i in range(1, total_number_of_lines):
	list_of_list.append(input_list[i])
	if(i%2 == 0):
		storage.append(list_of_list)
		list_of_list = []

result = 0
for i in range(len(storage)):
	temp = storage[i]
	first_line = temp[0].split(' ')
	second_line = temp[1]

	k = int(first_line[1])

	prev = 'H'
	count = 0

	for j in range(int(first_line[0])):
		if second_line[j] != 'H':
			if second_line[j] == prev:
				count += 1
			else:
				count = 0
				prev = second_line[j]
			if count == k:
				if second_line[j] == 'R':
					result -= 1
				elif second_line[j] == 'L':
					result += 1
				count = 0
	print(result)
	result = 0