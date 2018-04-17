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

void dfs(int& ans, vector<vector<int>>& edges, set<int>& visited, int cur, unordered_set<int>& pocketStops, int prevPocketStops) {
	visited.insert(cur);
	// if cur is a leaf
	if (edges[cur].size() == 1) {
		if (pocketStops.count(cur))
			ans = max(prevPocketStops+1, ans);
		else
			ans = max(prevPocketStops, ans);
	}
	int curPocketStops = pocketStops.find(cur) != pocketStops.end() ? prevPocketStops + 1 : prevPocketStops;
	// otherwise dfs
	for (int i = 0; i < edges[cur].size(); i++) {
		// haven't visited before
		if (visited.find(edges[cur][i]) == visited.end()) {
			dfs(ans, edges, visited, edges[cur][i], pocketStops, curPocketStops);
		}
	}
	visited.erase(cur);
}

int main(int argc, char** argv) {
	int t; 
	cin >> t; 
	cin.ignore();

	for (int i = 0; i < t; i++) {
		int n, p, e;
		cin >> n >> p >> e;
		cin.ignore();
		unordered_set<int> pocketStops;
		for (int j = 0; j < p; j++) {
			int stop;
			cin >> stop;
			pocketStops.insert(stop);
		}
		cin.ignore();
		vector<vector<int>> edges(n);

		for (int j = 0; j < e; j++) {
			int a, b;
			cin >> a >> b;
			cin.ignore();
			edges[a].push_back(b);
			edges[b].push_back(a);
		}

		set<int> visited;
		int ans = 0;
		// visited.insert(0);
		dfs(ans, edges, visited, 0, pocketStops, 0);
		// log(edges);
		cout<<ans<<endl;
	}
 	return 0;
}