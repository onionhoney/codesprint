#include <iostream>
using namespace std;

int main()
{
	int t = -1;
	int array[100];
	while (t < 0 || t > 100)
		cin >> t;
	for (int i = 0; i != t; i++)
	{
		int x;
		int total;
		int p, n, beauty, number;
		cin >> p, n;
		for (int j = 0; j != p; j++)
		{
			cin >> beauty, number;
			if (number <= n)
				beauty * number = x;
			else
				beauty * n = x;
			total + x = total;
			n - number = n
			if (n < 0)
				n = 0;
		}
		array[i] = total;
	}
	for (int si = 0; si != t; si++)
		cout << array[si] << endl;
	cout << endl;
}
