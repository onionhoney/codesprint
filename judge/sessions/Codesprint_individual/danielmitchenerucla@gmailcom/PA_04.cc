#include <iostream>
using namespace std;

int main()
{
	int t = -1;
	int array[100];
		cin >> t;
	for (int i = 0; i != t; i++)
	{
		int x;
		int total = 0;
		int p, n, beauty, number;
		cin >> p >> n;
		for (int j = 0; j != p; j++)
		{
			cin >> beauty >> number;
			if (number <= n)
				x = beauty * number;
			else
				x = beauty * n;
			total = x + total;
			n = n - number;
			if (n < 0)
				n = 0;
		}
		array[i] = total;
	}
	for (int si = 0; si != t; si++)
		cout << array[si] << endl;
	cout << endl;
}


