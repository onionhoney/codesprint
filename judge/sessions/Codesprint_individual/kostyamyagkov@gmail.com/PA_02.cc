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

int n, p, res, t;
vector <pair <int, int>> v;


int main()
{
	//	freopen("key.in", "r", stdin);
	//	freopen(".out", "r", stdout);
	cin >> t;
	while(t--)
	{
		cin >> p >> n;
		for(int i = 0; i < p; i++)
		{
			int b, num;
			cin >> b >> num;
			v.push_back(mp(b, num));
		}
		
		sort(all(v));
		reverse(all(v));
		
		for(int i = 0; i < p; i++)
			for(int j = 0; j < v[i].second; j++)
				if(n > 0)
				{
					n--;
					res += v[i].first;
				}
		
		cout << res << "\n";
		v.clear();
		res = 0;
	}
	
	return 0;
}






