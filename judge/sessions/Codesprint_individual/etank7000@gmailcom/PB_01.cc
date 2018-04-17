#include <iostream>

using namespace std;

int main()
{
	int t, m, n, k, h, v, x1, y1, x2, y2, ans = 1;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		h = 0;
		v = 0;
		ans = 1;
		cin >> m >> n;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 == x2)
			{
				v++;
				ans += h + 1;
			}
			else if (y1 == y2)
			{
				h++;
				ans += v + 1;
			}
		}
		cout << ans << endl;
	}
}