import sys
input_list = []

def getnzmaxp(arr):
	max_ent = 0
	max_pos = -1
	length = len(arr)
	for i in range(length):
		if arr[i] > max_ent and arr[i]!=0:
			max_pos = i
			max_ent = arr[i]
	return max_pos

def getnzminp(arr):
	min_ent = 100000
	min_pos = -1
	length = len(arr)
	for i in range(length):
		if arr[i] < min_ent and arr[i]!=0:
			min_pos = i
			min_ent = arr[i]
	return min_pos

def handle_case(data):
	num_ping = data[0][0]
	num_ppl = data[0][1]
	num_type = data[0][2]
	ment_arr = data[1]
	str_arr = data[2]
	result = 0
	while(num_ping > 0):
		if max(ment_arr) >= max(str_arr):
			max_pos = getnzmaxp(ment_arr)
			min_pos = getnzminp(str_arr)
			if max_pos == -1 or min_pos == -1:
				break;
			result += ment_arr[max_pos]
			ment_arr[max_pos] -= 1
			str_arr[min_pos] -= 1
		else:
			max_pos = getnzmaxp(str_arr)
			min_pos = getnzminp(ment_arr)
			if max_pos == -1 or min_pos == -1:
				break;
			result += str_arr[max_pos]
			str_arr[max_pos] -= 1
			ment_arr[min_pos] -= 1
		num_ping -= 1
	print(result)



def str2int(list):
	intlist = []
	for i in list:
		intlist.append(int(i))
	return intlist


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



for i in range(len(storage)):
	temp = storage[i]
	first_line = str2int(temp[0].split(' '))
	second_line = str2int(temp[1].split(' '))
	third_line = str2int(temp[2].split(' '))

	max_try = first_line[0]
	result = 0
	for j in range(max_try):
		if len(second_line) > 0 and len(third_line) > 0:
			max_x = max(second_line)
			max_y = max(third_line)
			min_all = 0
			min_x = min(second_line)
			min_y = min(third_line)
			if(max_x != max_y):
				if(max(max_x, max_y) == max_x):
					result += max_x
					second_line.remove(max_x)
					second_line.append(max_x - 1)
					min_all = min(third_line)
					third_line.remove(min_all)
					if(min_all > 1):
						third_line.append(min_all - 1)
				else:
					result += max_y
					third_line.remove(max_y)
					third_line.append(max_y - 1)
					min_all = min(second_line)
					second_line.remove(min_all)
					if(min_all > 1):
						second_line.append(min_all - 1)
			else:
				if(min(min_x, min_y) == min_x):
					result += max_y
					third_line.remove(max_y)
					third_line.append(max_y - 1)
					second_line.remove(min_x)
					if(min_x > 1):
						second_line.append(min_x -1)
				else:
					result += max_x
					second_line.remove(max_x)
					second_line.append(max_x -1)
					third_line.remove(min_y)
					if(min_y > 1):
						third_line.append(min_y -1)

	print(result)
	result = 0

