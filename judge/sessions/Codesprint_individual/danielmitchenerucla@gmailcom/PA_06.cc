#include <iostream>
using namespace std;

int main()
{
	int t = -1;
	int x, p, n, bi, ni, total;
	int array[100];
		cin >> t;
	for (int i = 0; i != t; i++)
	{
		total = 0;
		cin >> p >> n;
		for (int j = 0; j != p; j++)
		{
			cin >> bi >> ni;
			if (ni <= n)
				x = bi * ni;
			else
				x = bi * ni;
			total = x + total;
			n = n - ni;
			if (n < 0)
				n = 0;
		}
		array[i] = total;
	}
	for (int si = 0; si != t; si++)
		cout << array[si] << endl;
	cout << endl;
}


