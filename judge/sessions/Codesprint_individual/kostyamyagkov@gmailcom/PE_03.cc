#include <vector>
#include <stack>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <functional>
#include <set>
#include <cstring>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <complex>
#include <iterator>
#include <regex>
#include <fstream>
#define all(o) (o).begin(), (o).end()
#define mp(x, y) make_pair(x, y)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define sz(x) ((int)(x).size())
//#define x first
//#define y second
//#define pt pair <double, double>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int S = int(1e6) + 10;
const double INF = 1e9 + 7;
const ll MOD = 10007;
const double EPS = 1e-8;


int n, t;
ll dp[S];

int main()
{
	//	freopen("key.in", "r", stdin);
	//	freopen(".out", "r", stdout);
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4; i < S - 1; i++)
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % MOD;
	
	cin >> t;
	while(t--)
	{
		cin >> n;
		ll res = 1;
		for(int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			res = (res * dp[a]) % MOD;
		}
		cout << res << "\n";
	}
	
	return 0;
}
