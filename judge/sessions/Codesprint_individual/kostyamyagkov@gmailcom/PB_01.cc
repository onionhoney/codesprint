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

int m, n, k, t;


int main()
{
	//	freopen("key.in", "r", stdin);
	//	freopen(".out", "r", stdout);
	cin >> t;
	while(t--)
	{
		cin >> m >> n >> k;
		ll a = 0, b = 0;
		for(int i = 0; i < k; i++)
		{
			int x[2], y[2];
			scanf("%d%d%d%d", &x[0], &y[0], &x[1], &y[1]);
			if(x[0] == x[1])
				a++;
			else
				b++;
		}
		printf("%lld\n", (a+1)*(b+1));
	}
	
	return 0;
}






