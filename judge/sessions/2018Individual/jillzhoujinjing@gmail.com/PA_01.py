import sys

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
		if cur_case_line > 2:
			all_data[cur_case].append(line.strip('\n').split(' '))
		if cur_case_line == 4:
			cur_max = 0
			for one_size in all_data[cur_case][1]:
				for two_size in all_data[cur_case][2]:
					class_size = int(one_size) + int(two_size)
					if class_size <= all_data[cur_case][0]:
						if class_size > cur_max:
							cur_max = class_size
			print(cur_max)
			cur_case_line = 0
			cur_case +=1


