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
const int S = int(4e3) + 10;
const double INF = 1e9 + 7;
const ll MOD = ll(1e9) + 7;
const double EPS = 1e-8;

void print(vector <int> v)
{
	for(int i = 0; i < int(v.size()) - 1; i++)
		cout << v[i] << " ";
	cout << v.back() << "\n";
}

string f[110];
int n, m, t;


int main()
{
	//	freopen("key.in", "r", stdin);
	//	freopen(".out", "r", stdout);
	cin >> t;
	while(t--)
	{
		int si = 0, sj = 0, li = -1, lj = -1;
		cin >> n >> m >> si >> sj;
		si--;
		sj--;
		for(int i = 0; i < n; i++)
			cin >> f[i];
		string res = "";
		while(1)
		{
			int _li = si, _lj = sj;
			if(si > 0 && f[si - 1][sj] == '#' && mp(si - 1, sj) != mp(li, lj))
			{
				si--;
				res.push_back('U');
			}
			else if(si < n - 1 && f[si + 1][sj] == '#' && mp(si + 1, sj) != mp(li, lj))
			{
				si++;
				res.push_back('D');
			}
			else if(sj > 0 && f[si][sj - 1] == '#' && mp(si, sj - 1) != mp(li, lj))
			{
				sj--;
				res.push_back('L');
			}
			else if(sj < m - 1 && f[si][sj + 1] == '#' && mp(si, sj + 1) != mp(li, lj))
			{
				sj++;
				res.push_back('R');
			}
			else
				break;
			li = _li;
			lj = _lj;
		}
		cout << res << "\n";
	}
	
	return 0;
}






