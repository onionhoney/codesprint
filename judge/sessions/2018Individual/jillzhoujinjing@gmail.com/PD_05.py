import sys

def find_time(data):
	ele_floor = data[0]
	stop_floor = data[1]
	walk_floor = data[2]
	num_floor = data[3]
	floor_arr =list(set(data[5]))
	floor_arr.sort()
	num_ppl = len(floor_arr)
	min_sec = 1000000000
	record_ele = {}
	record_walk = {}
	for floor_th in floor_arr:
		ele_time = 0
		cur_sec = 0
		for i in range(num_ppl):
			if floor_arr[i] < floor_th:
				per_sec = (floor_arr[i]-1)*walk_floor
				record_walk[floor_arr[i]] = per_sec
				if per_sec > cur_sec:
					cur_sec = per_sec
			else:
				if ele_time == 0:
					per_sec = (floor_arr[i]-1) * ele_floor
					ele_time = per_sec + stop_floor
					if per_sec > cur_sec:
						cur_sec = per_sec
				else:
					per_sec = ele_time + (floor_arr[i]-floor_arr[i-1])*ele_floor
					ele_time += (floor_arr[i]-floor_arr[i-1])*ele_floor + stop_floor
					if per_sec > cur_sec:
						cur_sec = per_sec
		if cur_sec < min_sec:
			min_sec = cur_sec
	last_cal = (floor_arr[num_ppl-1]-1)*walk_floor
	if last_cal < min_sec:
		min_sec = last_cal
	return min_sec

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
			all_data[cur_case] = [int(line.strip('\n'))]
		elif cur_case_line < 6:
			all_data[cur_case].append(int(line.strip('\n')))
		else:
			all_data[cur_case].append(list(map(int,line.strip('\n').split(' '))))
		if cur_case_line == 6:
			print(find_time(all_data[cur_case]))
			cur_case += 1
			cur_case_line = 0