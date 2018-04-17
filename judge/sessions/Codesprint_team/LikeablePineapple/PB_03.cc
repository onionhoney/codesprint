#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <list>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <memory>
#include <math.h>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <regex>
#include <numeric>

using namespace std;

void log(string s) {
	cerr<<s<<endl;
}

void log(int i) {
	cerr<<i<<endl;
}

void log(char i) {
	cerr<<i<<endl;
}

void log(size_t i) {
	cerr<<i<<endl;
}

void log(long i) {
	cerr<<i<<endl;
}

void log(long long i) {
	cerr<<i<<endl;
}

void log(pair<string, string> p) {
    cerr<<p.first<<", "<<p.second<<endl;
}

void log(pair<int, int> p) {
	cerr<<p.first<<", "<<p.second<<endl;
}

void log(bool b) {
	if (b) 
		cerr<<"true"<<endl;
	else
		cerr<<"false"<<endl;
}

void log(vector<int> v) {
	string s = "[";
	for (auto i : v)
		s+= to_string(i) + ", ";
	if (s.size() > 1)
		s = s.substr(0, s.size() - 2);
	s += "]";
	cerr<<s<<endl;
}

void log(vector<string> v) {
	string s = "[";
	for (auto i : v)
		s+= i + ", ";
	if (s.size() > 1)
		s = s.substr(0, s.size() - 2);
	s += "]";
	cerr<<s<<endl;
}

string formatVec(vector<int> v) {
	string s = "[";
	for (auto i : v)
		s+= to_string(i) + ", ";
	if (s.size() > 1) 
		s = s.substr(0, s.size() - 2);
	s += "]";
	return s;
}

string formatVec(vector<string> v) {
	string s = "[";
	for (auto i : v)
		s+= i + ", ";
	if (s.size() > 1)
		s = s.substr(0, s.size() - 2);
	s += "]";
	return s;
}

template <class T>
void log(vector<vector<T>>& v) {
	string s = "[";
	for (auto i : v)
		s+= formatVec(i) + ", ";
	if (s.size() > 1)
		s = s.substr(0, s.size() - 2);
	s += "]";
	cerr<<s<<endl;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void log(ListNode* head) {
	string s;
	while (head) {
		s += to_string(head->val) + "->";
		head = head->next;
	}
	if (s.size() >= 2)
		s = s.substr(0, s.size() - 2);
	cerr<<s<<endl;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findNumCandles(vector<vector<int>>& board, int row, int col, int m, int n) {
	int ans = 0;
	ans += row > 0 && board[row-1][col] == -1 ? 1 : 0; // up
	ans += row > 0 && col > 0 &&  board[row-1][col-1] == -1 ? 1 : 0; // topleft
	ans += col > 0 && board[row][col-1] == -1 ? 1 : 0; // left
	ans += col > 0 && row + 1 < m && board[row+1][col-1] == -1 ? 1 : 0; // botLeft
	ans += row+1 < m && board[row+1][col] == -1 ? 1 : 0; // down
	ans += row+1 < m && col+1 < n && board[row+1][col+1] == -1 ? 1 : 0; // botRight
	ans += col < n && board[row][col+1] == -1 ? 1 : 0; // right
	ans += row > 0 && col+1 < n && board[row-1][col+1] == -1 ? 1 : 0; // topRight
	board[row][col] = ans;
	return ans;
}

int main(int argc, char** argv) {
	int t; 
	cin >> t; 
	cin.ignore();

	for (int i = 0; i < t; i++) {
		int m, n;
		cin >> m >> n;
		cin.ignore();
		int k;
		cin >> k;
		cin.ignore();

		vector<vector<int>> board(m, vector<int>(n, 0));
		int numCandles = 0;
		for (int j = 0; j < k; j++) {
			int row, col;
			cin >> row >> col;
			cin.ignore();
			board[row-1][col-1] = -1;
		}
		// log(board);
		for (int r = 0; r < m; r++) {
			for (int c = 0; c < n; c++) {
				if (board[r][c] != -1) {
					numCandles += findNumCandles(board, r, c, m, n);
				}
			}
		}
		// log(board);
		cout<<numCandles<<endl;
	}

 	return 0;
}