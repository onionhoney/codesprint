#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int t, m, n;
string s[100];
bool bj[100][100];
string result;

void dfs(int a, int b, const int m, const int n)
{
	if (a >= m || a < 0 || b >= n || b < 0) return;
	else {
		if (a + 1 < m && s[a + 1][b] == '#' && bj[a + 1][b])
		{
			result = result + 'D';
			bj[a + 1][b] = false;
			dfs(a + 1, b, m, n);
			//result = result - 'D';
		}
		if (a - 1 >= 0 && s[a - 1][b] == '#' && bj[a - 1][b])
		{
			result = result + 'U';
			bj[a - 1][b] = false;
			dfs(a - 1, b, m, n);
			//result = result - 'U';
		}
		if (b - 1 >= 0 && s[a][b - 1] == '#' && bj[a][b - 1])
		{
			result = result + 'L';
			bj[a][b - 1] = false;
			dfs(a, b - 1, m, n);
			//result = result - "R";
		}
		if (b + 1 < n && s[a][b + 1] == '#' && bj[a][b + 1])
		{
			result = result + 'R';
			bj[a][b + 1] = false;
			dfs(a, b + 1, m, n);
			//result = result - 'R';
		}
	}
}


int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		result = "";
		for (int ss = 0; ss < 100; ss++)
			for (int sss = 0; sss < 100; sss++)
				bj[ss][sss] = true;
		cin >> m >> n;
		int a, b;
		cin >> a >> b;
		cin.ignore(10000, '\n');
		for (int j = 0; j < m; j++)
			getline(cin, s[j]);
		for (int j = 0; j < m; j++)
			cout << s[j] << endl;
		dfs(a - 1, b - 1, m, n);
		cout << result << endl;
	}

}
