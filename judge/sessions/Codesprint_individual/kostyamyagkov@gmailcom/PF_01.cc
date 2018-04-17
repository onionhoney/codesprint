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
const int INF = int(1e9) + 7;
const ll MOD = ll(1e4) + 7;
const double EPS = 1e-8;

void print(vector <int> v)
{
	for(int i = 0; i < int(v.size()) - 1; i++)
		cout << v[i] << " ";
	cout << v.back() << "\n";
}

vector <string> v;
int n, m, t, k;
ll dp[S], s[110];

int main()
{
	//	freopen("key.in", "r", stdin);
	//	freopen(".out", "r", stdout);
	
	cin >> t;
	while(t--)
	{
		cin >> n >> k >> m;
		vector < vector < pair<int,int> > > g (n);
		vector <int> pl(k), tw(k);
		for(int i = 0; i < k; i++)
		{
			cin >> pl[i] >> tw[i];
			pl[i]--;
		}
		for(int i = 0; i < k; i++)
			for(int j = 0; j < k; j++)
				if(i != j)
				{
					g[pl[i]].push_back(mp(pl[j], tw[i]));
					g[pl[j]].push_back(mp(pl[i], tw[j]));
				}
		for(int i = 0; i < m; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			a--;
			b--;
			g[a].push_back(mp(b, c));
			g[b].push_back(mp(a, c));
		}
		int s = 0;
		vector<int> d (n, INF),  p (n);
		d[s] = 0;
		vector<char> u (n, 0);
		for (int i=0; i<n; ++i)
		{
			int v = -1;
			for (int j=0; j<n; ++j)
				if (!u[j] && (v == -1 || d[j] < d[v]))
					v = j;
			if (d[v] == INF)
				break;
			u[v] = true;
			for (int j=0; j<g[v].size(); ++j)
			{
				int to = g[v][j].first,
				len = g[v][j].second;
				if (d[v] + len < d[to])
				{
					d[to] = d[v] + len;
					p[to] = v;
				}
			}
		}
		cout << d[n - 1] << "\n";
	}

	return 0;
}






