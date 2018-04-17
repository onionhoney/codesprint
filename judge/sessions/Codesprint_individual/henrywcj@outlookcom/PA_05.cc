#include <iostream>
#include <string>
#include <cctype>
using namespace std;

long f[1000001];

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		int a, ans = 1;
		f[1] = 1;
		f[2] = 2;
		f[3] = 4;
		for (int j = 4; j <= 1000000; j++)
		{
			f[j] = (f[j - 1] + f[j - 2] + f[j - 3] ) % 10007;
		}
		for (int k = 0; k < n; k++)
		{
			cin >> a;
			ans = (ans % 10007) * f[a];
		}
		cout << ans % 10007 << endl;
	}
}