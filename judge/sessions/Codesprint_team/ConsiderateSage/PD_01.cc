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
const int S = int(1e4) + 10;
const double INF = 1e9 + 7;
const ll MOD = ll(1e4) + 7;
const double EPS = 1e-8;

void print(vector <int> v)
{
	for(int i = 0; i < int(v.size()) - 1; i++)
		cout << v[i] << " ";
	cout << v.back() << "\n";
}

vector <vector <int>> g;
int n, poke[S], p, res, t, m;

void dfs(int v, int from, int stops)
{
	for(int i = 0; i < int(g[v].size()); i++)
		if(g[v][i] != from)
			dfs(g[v][i], v, (poke[v] ? stops + 1 : stops));
	res = max(res, (poke[v] ? stops + 1 : stops));
	int x = 1;
}

int main()
{
	//	freopen("key.in", "r", stdin);
	//	freopen(".out", "r", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n >> p >> m;
		g.clear();
		res = 0;
		memset(poke, 0, n*sizeof(int));
		g.resize(n);
		for(int i = 0; i < p; i++)
		{
			int a;
			scanf("%d", &a);
			poke[a] = 1;
		}
		
		for(int i = 0; i < n - 1; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		dfs(0, -1, 0);
		cout << res << "\n";
	}
	
	return 0;
}






