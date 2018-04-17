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

string formatVec(vector<char> v) {
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


vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

void dfs(vector<vector<char>>& board, int row, int col, int m, int n, string& ans) {
	board[row][col] = '.';
	bool end = true;
	for (int i = 0; i < 4; i++) {
		int nextRow = row + directions[i][0];
		int nextCol = col + directions[i][1];
		if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && board[nextRow][nextCol] == '#') {
			end = false;
			if (i == 0)
				ans += 'D';
			if (i == 1)
				ans += 'U';
			if (i == 2)
				ans += 'R';
			if (i == 3)
				ans += 'L';

			dfs(board, nextRow, nextCol, m, n, ans);
		}
	}
	if (end)
		cout<<ans<<endl;
}

int main(int argc, char** argv) {
	int t; 
	cin >> t; 
	cin.ignore();

	for (int i = 0; i < t; i++) {
		int m, n;
		cin >> m >> n;
		cin.ignore();
		int a, b;
		cin >> a >> b;
		cin.ignore();
		vector<vector<char>> board(m, vector<char>(n));
		for (int row = 0; row < m; row++) {
			for (int col = 0; col < n; col++) {
				cin >> board[row][col];
			}
			cin.ignore();
		}
		a--;
		b--;
		string ans;
		dfs(board, a, b, m, n, ans);
		// log(board);
	}
 	return 0;
}