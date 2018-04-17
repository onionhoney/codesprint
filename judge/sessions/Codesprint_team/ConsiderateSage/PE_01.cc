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
const ll magic = 1000;
const double EPS = 1e-8;

void print(vector <int> v)
{
	for(int i = 0; i < int(v.size()) - 1; i++)
		cout << v[i] << " ";
	cout << v.back() << "\n";
}

int r, t;

ll sqr(ll cap)
{
	ll l = 0, r = ll(1e4);
	while(r - l > 1)
	{
		ll m = (l+r)/2;
		if(magic*magic*m*m <= cap)
			l = m;
		else
			r = m;
	}
	return 2*l + 1;
}

ll getnum(int dx)
{
	ll res = 0;
	for(int a = -r - 4; a <= r + 4; a++)
	{
		ll bsq = magic*magic*r*r - (magic*a - dx)*(magic*a - dx);
		if(bsq >= 0)
			res += sqr(bsq);
	}
	return res;
}

int main()
{
	//	freopen("key.in", "r", stdin);
	//	freopen(".out", "r", stdout);
	cin >> t;
	while(t--)
	{
		cin >> r;
		ll res = 0;
		for(int i = 0; i < magic; i++)
			res = max(res, getnum(i));
		cout << res << "\n";
	}
	
	return 0;
}






