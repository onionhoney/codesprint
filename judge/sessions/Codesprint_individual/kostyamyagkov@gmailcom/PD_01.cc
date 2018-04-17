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

vector <string> v;
int n, m, t;


int main()
{
	//	freopen("key.in", "r", stdin);
	//	freopen(".out", "r", stdout);
	
	cin >> n;
	cin.ignore(100, '\n');
	v.resize(n);
	int k[4];
	char res[4] = {'a', 'a', 'a', 'a'};
	for(int i = 0; i < n; i++)
	{
		getline(cin, v[i]);
		while(isspace(v[i].back()))
			v[i].pop_back();
	}
	for(int i = 0; i < 4; i++)
		cin >> k[i];
	
	for(int i = 0; i < n; i++)
	{
		istringstream strm(v[i]);
		int l, r;
		char c;
		strm >> l >> r;
		c = v[i].back();
		for(int i = 0; i < 4; i++)
			if(k[i] >= l && k[i] <= r)
				res[i] = c;
	}
	printf("%c %c %c %c \n", res[0], res[1], res[2], res[3]);
	
	return 0;
}






