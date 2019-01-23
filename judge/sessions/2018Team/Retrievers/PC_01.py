import sys

def calc_num(num_bot,num_sec,expl_arr,dest_arr):
	if num_sec <= 0:
		return 0;
	elif num_bot <= 0:
		return 0;
	#if explode
	num_dest = dest_arr[0]
	prob_ex = expl_arr[0]
	explode_avg = calc_num(num_bot-num_dest-1, num_sec-num_dest-1, expl_arr[(num_dest+1):], dest_arr[(num_dest+1):])
	not_explode_avg = 1+calc_num(num_bot-1, num_sec-1, expl_arr[1:],dest_arr[1:])
	return prob_ex*explode_avg+(1.0-prob_ex)*not_explode_avg

def handle_case(data):
	num_bot = data[0][0]
	num_sec = data[0][1]
	expl_arr = data[1]
	dest_arr = data[2]
	print(int(calc_num(num_bot,num_sec,expl_arr,dest_arr)))


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
			all_data[cur_case] = [list(map(int,line.rstrip().strip('\n').split(' ')))]
		elif cur_case_line == 2:
			all_data[cur_case].append(list(map(float,line.rstrip().strip('\n').split(' '))))
		else:
			all_data[cur_case].append(list(map(int,line.rstrip().strip('\n').split(' '))))
		if cur_case_line == 3:
			handle_case(all_data[cur_case])
			cur_case_line = 0
			cur_case +=1