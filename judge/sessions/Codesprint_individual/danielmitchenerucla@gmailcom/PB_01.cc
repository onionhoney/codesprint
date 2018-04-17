#include <iostream>
using namespace std;

int main()
{
	int array[100];
	int t;
	cin >> t;
	for (int i = 0; i != t; i++)
	{
		int m, n;
		cin >> m >> n;
		int k;
		cin >> k;
		int rows = 1;
		int cols = 1;
		for (int j = 0; j != k; j++)
		{
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 == x2)
				rows++;
			else if (y1 == y2)
				cols++;
		}
		array[i] = rows * cols;
	}
	for (int q = 0; q != t; q++)
		cout << array[q] << endl;
}