#include <iostream>

using namespace std;

int main()
{
	int t, p, n, b, k, ans;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		ans = 0;
		cin >> p >> n;
		while (n > 0 && p > 0)
		{
			cin >> b >> k;
			while (n > 0 && k > 0)
			{
				ans += b;
				k--;
				n--;
			}
			p--;
		}
		while (p > 0)
			cin >> b >> k;
		cout << ans << endl;
	}
}
