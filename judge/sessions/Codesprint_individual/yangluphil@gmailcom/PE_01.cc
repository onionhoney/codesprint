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

int main(int argc, char** argv) {
	int t; 
	cin >> t; 
	cin.ignore();
	vector<int> dp(1000001, 0);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 10007;
	}
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cin.ignore();
		int ans = 1;
		for (int j = 0; j < n; j++) {
			int s;
			cin >> s;
			ans = ans * dp[s] % 10007;
		}
		cout<<ans<<endl;
	}
 	return 0;
}