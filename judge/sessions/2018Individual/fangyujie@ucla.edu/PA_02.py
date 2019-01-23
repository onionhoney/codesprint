import sys

input_list = []

def read():
	count = 0
	for line in sys.stdin:
		input_list.append(line.rstrip())
		count += 1
		if count == int(input_list[0])*4 + 1:
			return count

total_number_of_lines = read()

storage = []
list_of_list = []
for i in range(1, total_number_of_lines):
	list_of_list.append(input_list[i])
	if(i%4 == 0):
		storage.append(list_of_list)
		list_of_list = []


max = 0
for i in range(len(storage)):
	temp = storage[i]
	max_jump = int(temp[0])
	options = temp[1].split(' ')
	first_option = int(options[0])
	second_option = int(options[1])

	size_of_31 = temp[2].split(' ')

	#print(size_of_31)
	size_of_32 = temp[3].split(' ')
	#print(size_of_32)

	for i in size_of_31:
		for j in size_of_32:
			sum = int(i) + int(j)
			if sum > max and sum < max_jump:
				max = sum
	print(max)
	max = 0


