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

	for (int i = 0; i < t; i++) {
		int n, k, r;
		cin >> n >> k >> r;
		cin.ignore();
		map<int, int> wormholes;
		unordered_map<int, unordered_map<int, int>> routes;
		for (int j = 0 ; j < k; j++) {
			int a, t;
			cin >> a >> t;
			cin.ignore();
			wormholes[a] = t;
		}

		for (int j = 0; j < r; j++) {
			int a, b, t;
			cin >> a >> b >> t;
			cin.ignore();
			routes[a][b] = t;
			routes[b][a] = t;
		}

		vector<int> dp(n+1, INT_MAX);
		dp[1] = 0;
		for (int j = 2; j <= n; j++) {
			for (auto& entry : routes[j]) {
				if (dp[entry.first] != INT_MAX) {
					dp[j] = min(dp[j], dp[entry.first] + routes[j][entry.first]);
				}
			}
			if (wormholes.count(j)) {
				// update dp[j] for wormholes
				for (auto& entry : wormholes) {
					if (entry.first >= j || dp[entry.first] == INT_MAX)
						break;
					dp[j] = min(dp[j], wormholes[entry.first] + dp[entry.first]);
				}

				// update all previous wormholes
				if (dp[j] != INT_MAX) {
					for (auto& entry : wormholes) {
						if (entry.first >= j)
							break;
						dp[entry.first] = min(dp[entry.first], dp[j] + wormholes[j]);
					}
				}
			}
		}
		cout<<dp[n]<<endl;
	}
 	return 0;
}