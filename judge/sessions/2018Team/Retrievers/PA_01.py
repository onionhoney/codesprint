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
			all_data[cur_case] = [list(map(int,line.strip('\n').split(' ')))]
		else:
			all_data[cur_case].append(line.strip('\n'))
		if cur_case_line == 2:
			result = 0
			num_con = all_data[cur_case][0][1]
			record = all_data[cur_case][1]
			add_dict = {'R':-1, 'L': 1,'H':0}
			con_dict = {'R':0, 'L':0, 'H':0}
			last_let = 'H'
			first_letter = 1
			for letter in record:
				if first_letter:
					first_letter = 0
					last_let = letter
					con_dict[letter] = 1
				else:
					if letter == last_let:
						con_dict[letter] +=1
					elif con_dict[last_let] >=num_con:
						result += add_dict[last_let]
						con_dict[last_let] = 0
						con_dict[letter] = 1
						last_let = letter
					else:
						con_dict[last_let] = 0
						con_dict[letter] = 1
						last_let = letter
			if con_dict[last_let] >=3:
				result += add_dict[last_let]
			print(result)
			cur_case += 1
			cur_case_line = 0




