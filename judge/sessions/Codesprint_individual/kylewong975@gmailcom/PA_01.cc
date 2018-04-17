#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <list>

using namespace std;

int main()
{
	//cin, cout, cout.setf(ios::fixed), cout.precision(number of digits to the right of the decimal), getline(cin, variable), cin.ignore(10000, '\n')
	int testCases;
	cin >> testCases;
	for (int x = 0; x < testCases; x++)
	{
		int nTypes, battery;
		int beauty = 0;
		cin >> nTypes >> battery;
		for (int y = 0; y < nTypes; y++)
		{
			int b, count;
			cin >> b >> count;
			if (battery <= 0) continue;
			if (battery - count <= 0)
			{
				beauty += b * battery;
				battery = 0;
			}
			else
			{
				beauty += count*b;
				battery -= count;
			}
		}
		cout << beauty << endl;
	}
}