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
using namespace std;

void game();
void mine();
void test();
void small();
void tun();
void boelter();

int main(int argc, const char * argv[]) {
	
	tun();
	
	return 0;
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
		
		for(int i = 0; i < 99; i++) {
			int temp;
			cin >> temp;
			if(temp == 1)
				ans += to_string(i) + " ";
		}
		
		cin.ignore(1000, '\n');
		
		for(int i = 0; i < 99; i++) {
			int temp;
			cin >> temp;
			if(temp == 1)
				ans += to_string(i) + " ";
		}
		
		cin.ignore(1000, '\n');
		
		for(int i = 0; i < 99; i++) {
			int temp;
			cin >> temp;
			if(temp == 1)
				ans += to_string(i);
		}
		cin.ignore(1000, '\n');
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
