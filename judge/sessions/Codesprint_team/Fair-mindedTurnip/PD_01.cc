#include <iostream>
#include <string>
using namespace std;
bool bj[10000][10000];
int main() {
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		int n, p, e;
		bool b[10000];
		for (int j = 0; j < 10000; j++)
			b[j] = false;
		cin >> n >> p >> e;
		for (int j = 0; j < p; j++)
		{
			int a;
			cin >> a;
			b[a] = true;
		}
		for (int j = 0; j < 10000; j++)
			for (int k = 0; k < 10000; k++) bj[j][k] = false;
		for (int j = 0; j < e; j++)
		{
			int a, c;
			cin >> a >> c;
			bj[a][c] = true;
			bj[c][a] = true;
		}
		int f[10000];
		if (b[0] ) f[0] = 1;
		else f[0] = 0;
		for (int j = 1; j < n; j++)
		{
			for (int k = 0; k < j; k++)
			{
				if (bj[j][k] && b[j]) f[j] = 1 + f[k];
				else if (bj[j][k]) f[j] = f[k];
			}
		}
		int max = 0;
		for (int j = 1; j < n; j++)
			if (f[j] > max) max = f[j];
		cout << max << endl;
	}
}