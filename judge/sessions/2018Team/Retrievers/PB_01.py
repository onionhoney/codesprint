import sys

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


first_line = 1
cur_case = 0
cur_case_line = 0
all_data = {}
for line in sys.stdin:
	if first_line:
		first_line = 0
	else:
		cur_case_line +=1
		if cur_case not in all_data:
			all_data[cur_case] = [list(map(int,line.strip('\n').split(' ')))]
		else:
			all_data[cur_case].append(list(map(int,line.strip('\n').split(' '))))
		if cur_case_line == 3:
			handle_case(all_data[cur_case])
			cur_case_line = 0
			cur_case +=1