#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Point {
	public:
		Point(int x, int y);
		int row;
		int col;
};
Point::Point(int x, int y) {
		this->row = x;
		this->col = y;
}

string interpret(int row, int col, Point sp) {
	vector<string> row_data;
	row_data.push_back("dummya");
	for (int i = 0; i < row; i++) {
		string str;
		getline(cin, str);
//		cout << "HI! " << str << "\n" << "next: " << i << "\n";
		row_data.push_back("#" + str);
	}
	//cout <<"????\n";
	vector<vector<bool> > visited;
	vector<bool> dummy;
	dummy.push_back(true);
	for (int j = 0; j < col; j++) {
		dummy.push_back(true);
	}
	visited.push_back(dummy);
	
	for (int i = 1; i < row+1; i++) {
		vector<bool> b;
		visited.push_back(b);
		visited[i].push_back(true);
		for (int j = 0; j < col; j++) {
			visited[i].push_back(false);
		}
	}
	
	Point cp(sp.row, sp.col);
	
//	for (int i = 0; i < row_data.size(); i++) {
//		cout << row_data[i] << "\n";
//	}
//	
//	for (int i = 0; i < visited.size(); i++) {
//		for (int j = 0; j < visited[i].size(); j++) {
//			cout << visited[i][j] << " ";
//		}
//		cout << "\n";
//	}
	
	string out = "";
	while (true) {
		if (cp.row+1 <= row && (row_data[cp.row+1][cp.col] == '#')) {
			if (visited[cp.row+1][cp.col] == false) {
				out += 'D';
				visited[cp.row+1][cp.col] = true;
				cp.row++;
				continue;
			}
		} 
		if (cp.row-1 > 0 && (row_data[cp.row-1][cp.col] == '#')) {
			if (visited[cp.row-1][cp.col] == false) {
				out += 'U';
				visited[cp.row-1][cp.col] = true;
				cp.row--;
				continue;
			}
		} 
		if (cp.col+1 <= col && (row_data[cp.row][cp.col+1] == '#')) {
			if (visited[cp.row][cp.col+1] == false) {
				out += 'R';
				visited[cp.row][cp.col+1] = true;
				cp.col++;
				continue;
			}
		} 
		if (cp.row-1 <= row && (row_data[cp.row][cp.col-1] == '#')) {
			if (visited[cp.row][cp.col-1] == false) {
				out += 'L';
				visited[cp.row][cp.col-1] = true;
				cp.col--;
				continue;
			}
		}
		
		break;
		//cout << "c";
	}
	return out;
}



int main(int argc, char *argv[]) {
	int test_case;
	cin >> test_case;
	
	vector<string> results;
	
	for (int k = 0; k < test_case; k++) {
		int row, col;
		cin >> row;
		cin >> col;
		int sa, sb;
		cin >> sa; 
		cin >> sb;
		Point sp(sa, sb);
		string dummy;
		getline(cin, dummy);
		
		results.push_back(interpret(row, col, sp));
	}
	
	for (int m = 0; m < results.size(); m++) {
		cout << results[m] << "\n";
	}
}