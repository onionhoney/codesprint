//
//  main.cpp
//  CodeSprint2018
//
//  Created by Alexander Chen on 5/20/18.
//  Copyright © 2018 Alexander Chen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <cmath>
#include <unordered_map>
#include <math.h>
using namespace std;

void game();
void mine();
void test();
void small();
void tun();
void boelter();
void cheat();
void game2();
void spam();
void aimbot();
void bots();

int main(int argc, const char * argv[]) {
	
	bots();
	
	return 0;
}

void bots() {
	int c;
	cin >> c;
	for(int test = 0; test < c; test++) {
		int n, s;
		cin >> n >> s;
		vector<double> probs(n);
		for(int i = n - 1; i >= 0; i--) { //in reverse order
			cin >> probs[i];
		}
		vector<double> boom(n);
		for(int i = n - 1; i >=0; i--) { //in reverse order
			cin >> boom[i];
		}

		int size = min(s, n);
		probs = vector<double>(probs.end() - size, probs.end());
		boom = vector<double>(boom.end() - size, boom.end());
		vector<double>dp(size);
		
		dp[0] = 1 - probs[0];
		
		for(int i = 1; i < size; i++) {
			double survive = 1 + dp[i-1];
			double explode = 0;
			if(i - boom[i] >= 0) {
				explode = dp[i - boom[i] - 1];
			}
			dp[i] = probs[i] * explode + (1-probs[i]) * survive;
		}
		
		cout << (int)dp[size-1] << endl;
	}
}



void aimbot() {
	int t;
	cin >> t;
	for(int test = 0; test < t; test++) {
		int n, k;
		cin >> n >> k;
		string s;
		cin.ignore(1000, '\n');
		getline(cin, s);
		
		int adj = 0;
		
		for(int i = 0; i < n - k + 1; i++) {
			bool add = true;
			bool sub = true;
			
			
			for(int j = 0; j < k; j++) {
				if(s[i+j] == 'H') {
					add = false;
					sub = false;
				}
				if(s[i+j] == 'R')
					add = false;
				if(s[i+j] == 'L')
					sub = false;
			}
			
			if(add) {
				i += k - 1;
				adj++;
			}
			else if(sub) {
				i += k - 1;
				adj--;
			}
			
		}
		
		cout << adj << endl;
		
	}
}

void games() {
	int t;
	cin >> t;
	for(int test = 0; test < t; test++) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		
		
	}
}

void spam() {
	int c;
	cin >> c;
	for(int test = 0; test < c; test++) {
		int n, p, q;
		cin >> n >> p >> q;
		
		
		vector<int> instability(p);
		vector<int> tilting(q);
		
		for(int i = 0; i < p; i++) {
			cin >> instability[i];
		}
		for(int j = 0; j < q; j++) {
			cin >> tilting[j];
		}
		
		int unhappiness = 0;
		
		sort(instability.begin(), instability.end());
		sort(tilting.begin(), tilting.end());
		
		while(!instability.empty() && !tilting.empty() && n > 0) {
			
			if(instability[instability.size() - 1] == tilting[tilting.size() - 1]) {
				if(instability[0] <= tilting[0]) {
					unhappiness += tilting[tilting.size() - 1];
					tilting[tilting.size() - 1]--;
					instability[0]--;
					if(tilting[tilting.size() - 1] == 0)
						tilting.pop_back();
					if(instability[0] == 0) {
						instability = vector<int>(instability.begin() + 1, instability.end());
					}
				}
				else {
					unhappiness += instability[instability.size() - 1];
					instability[instability.size() - 1]--;
					tilting[0]--;
					if(instability[instability.size() - 1] == 0)
						instability.pop_back();
					if(tilting[0] == 0) {
						tilting = vector<int>(tilting.begin() + 1, tilting.end());
					}
				}
			}
			else if(instability[instability.size() - 1] > tilting[tilting.size() - 1]) {
				unhappiness += instability[instability.size() - 1];
				instability[instability.size() - 1]--;
				tilting[0]--;
				if(instability[instability.size() - 1] == 0)
					instability.pop_back();
				if(tilting[0] == 0) {
					tilting = vector<int>(tilting.begin() + 1, tilting.end());
				}
			}
			else {
				unhappiness += tilting[tilting.size() - 1];
				tilting[tilting.size() - 1]--;
				instability[0]--;
				if(tilting[tilting.size() - 1] == 0)
					tilting.pop_back();
				if(instability[0] == 0) {
					instability = vector<int>(instability.begin() + 1, instability.end());
				}
			}
			sort(instability.begin(), instability.end());
			sort(tilting.begin(), tilting.end());
			n--;
		}
		
		cout << unhappiness << endl;
	}
}

vector<char> rec(vector<char> letters, bool a) {
	if(letters.size() == 2) {
		if(a) {
			if(letters[0] == 'A' || letters[1] == 'A')
				return vector<char>(1, 'A');
			else
				return vector<char>(1, 'B');
		}
		else {
			if(letters[0] == 'B' || letters[1] == 'B')
				return vector<char>(1, 'B');
			else
				return vector<char>(1, 'A');
		}
	}
	
	int newsize = letters.size() / 2;
	
	if(a) {
		int maxa = 0;
		int start = 0;
		for(int i = 0; i <= newsize; i++) {
			int numa = 0;
			for(int j = 0; j < newsize; j++) {
				if(letters[i+j] == 'A')
					numa++;
			}
			if(numa > maxa) {
				maxa = numa;
				start = i;
			}
		}
		
		vector<char> newl(letters.begin() + start, letters.begin() + start + newsize);
		
		return rec(newl, false);
	}
	else {
		int maxb = 0;
		int start = 0;
		for(int i = 0; i <= newsize; i++) {
			int numb = 0;
			for(int j = 0; j < newsize; j++) {
				if(letters[i+j] == 'B')
					numb++;
			}
			if(numb > maxb) {
				maxb = numb;
				start = i;
			}
		}
		
		vector<char> newl(letters.begin() + start, letters.begin() + start + newsize);
		
		return rec(newl, true);
	}
}

void game2() {
	int t;
	cin >> t;
	for(int test = 0; test < t; test++) {
		int n;
		cin >> n;
		int size = floor(pow(2, n));
		vector<char> letters(size);
		
		for(int i = 0; i < size; i++)
			cin >> letters[i];
		
		vector<char> ans = rec(letters, true);
		
		cout << ans[0] << endl;
		
	}
}




void cheat() { //if only a substring is used, then bits can be reduced
	int t;
	cin >> t;
	for(int test = 0; test < t; test++) {
		int N, C;
		cin >> N >> C;
		
		string s;
		cin.ignore(1000, '\n');
		getline(cin, s);
		
		
		int max = 0;
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N - i + 1; j++) {
				int num = 0;
				unordered_map<char, int> dict;
				for(int k = i; k < i + j; k++) {
					if(dict[s[k]] == 0)
						num++;
					dict[s[k]]++;
				}
				
				int chars = ceil(log2(num));
				
				if(j * chars <= C && j > max)
					max = j;
			}
		}
		
		cout << max << endl;
		
	}
}

void boelter() {
	int c;
	cin >> c;
	for(int i = 0; i < c; i++) {
		int n, l, k;
		cin >> n >> l >> k;
		for(int j = 0; j < l; j++) {
			
		}
	}
}

void tun() {
	int n;
	cin >> n;
	for(int j = 0; j < n; j++) {
		
		string ans = "";
		
		for(int i = 0; i < 100; i++) {
			int temp;
			cin >> temp;
			if(temp == 1)
				ans += to_string(i) + " ";
		}
		
		//cin.ignore(1000, '\n');
		
		for(int i = 0; i < 100; i++) {
			int temp;
			cin >> temp;
			if(temp == 1)
				ans += to_string(i) + " ";
		}
		
		//cin.ignore(1000, '\n');
		
		for(int i = 0; i < 100; i++) {
			int temp;
			cin >> temp;
			if(temp == 1)
				ans += to_string(i);
		}
		//cin.ignore(1000, '\n');
		cout << ans << endl;
		
	}
}


void small() {
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int p, q;
		cin >> p >> q;
		vector<int> cs31(p);
		vector<int> cs32(q);
		for(int i = 0; i < p; i++) {
			cin >> cs31[i];
		}
		for(int j = 0; j < q; j++) {
			cin >> cs32[j];
		}
		
		int max = 0;
		
		for(int i = 0; i < p; i++) {
			for(int j = 0; j < q; j++) {
				if(cs31[i] + cs32[j] <= n && cs31[i] + cs32[j] > max)
					max = cs31[i] + cs32[j];
			}
		}
		cout << max << endl;
	}
}

void elev() {
	int t;
	cin >> t;
	
}

void test() {
	typedef long long ll;
	typedef vector<ll> vi;
	
	int n; cin >> n;
	
	vi a(n);
	ll maxx = 0;
	for(int i =0; i < n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	vi dp(maxx + 2);
	const ll MOD = 100000007LL;
	dp[1] = 1; dp[2] = 1;
	for(int i = 3;i <= maxx; i++) {
		dp[i] = (dp[i-1] + dp[i-2]) % MOD;
	}
	for(int i = 0; i < n; i ++) {
		cout << dp[a[i]] << endl;
	}
}

void mine() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<char>> grid(n, vector<char>(m));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == '*')
				continue;
			
			int sum = '0';
			if(i - 1 >= 0 && j - 1 >= 0 && grid[i-1][j-1] == '*')
				sum++;
			if(i - 1 >= 0)
				sum += grid[i-1][j];
			if(i-1 >= 0 && j+1 < n && grid[i-1][j+1] == '*')
				sum++;
			if(j+1 < n && grid[i][j+1] == '*')
				sum++;
			if(i+1 < n && j+1 < n && grid[i+1][j+1] == '*')
				sum++;
			if(i+1 < n && grid[i+1][j] == '*')
				sum++;
			if(i+1 < n && j-1 >= 0 && grid[i+1][j-1] == '*')
				sum++;
			if(j-1 >= 0 && grid[i][j-1] == '*')
				sum++;
			
			
			if(sum != grid[i][j]) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
	
}

void game() {
	
	int size;
	cin >> size;
	vector<int> nums(size);
	
	for(int i = 0; i < size; i++) {
		cin >> nums[i];
	}
	
	sort(nums.begin(), nums.end());
	
	int index;
	if(nums.size() % 2 == 1)
		index = nums.size() / 2;
	else
		index = nums.size() / 2 - 1;
	
	cout << nums[index] << endl;
}
