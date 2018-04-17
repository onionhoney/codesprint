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
const int S = int(1e3) + 10;
const double INF = 1e9 + 7;
const ll MOD = ll(1e4) + 7;
const ll magic = 2000;
const double EPS = 1e-8;

int d, n, r, t;

int main()
{
	//	freopen("key.in", "r", stdin);
	//	freopen(".out", "r", stdout);
	cin >> t;
	while(t--)
	{
		cin >> d >> n >> r;
		int res = -1;
		vector <int> l(n), p(n);
		for(int i = 0; i < n; i++)
			scanf("%d%d", &l[i], &p[i]);
		for(int v = 1; v <= r; v++)
		{
			bool flag = true;
			for(int i = 0; i < n; i++)
				if(l[i] % (2*p[i]*v) >= p[i]*v)
					flag = false;
			if(flag)
				res = v;
		}
		cout << res << "\n";
	}
	
	return 0;
}






