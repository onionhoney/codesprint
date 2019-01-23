import sys

def find_one(data,min_p,max_p):
	index = int((min_p+max_p)/2)
	dif = max_p - min_p
	if dif == 0:
		return max_p
	if dif == 1:
		if data[max_p] == 1:
			return max_p
		elif data[min_p] == 1:
			return min_p
	if data[index] == 2:
		return find_one(data,min_p,index+1)
	elif data[index] == 0:
		return find_one(data,index-1, max_p)
	else:
		return index


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
			result = ""
			for i in range(3):
				data = all_data[cur_case][i]
				if i < 2:
					result += str(find_one(data,0,99)) + ' '
				else:
					result += str(find_one(data,0,99))
			print(result)
			cur_case += 1
			cur_case_line = 0






