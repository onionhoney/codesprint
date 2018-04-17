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

int f[S][S], n, m, t, k;

void addcell(int &res, int i, int j)
{
	if(i >= 0 && i < n && j >= 0 && j < m)
		res += f[i][j];
}

int main()
{
	//	freopen("key.in", "r", stdin);
	//	freopen(".out", "r", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> k;
		for(int i = 0; i < k; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			a--;
			b--;
			f[a][b] = 1;
		}
		int res = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(!f[i][j])
					for(int di = -1; di <= 1; di++)
						for(int dj = -1; dj <= 1; dj++)
							if(di || dj)
								addcell(res, i + di, j + dj);
		cout << res << "\n";
	}
	
	return 0;
}






