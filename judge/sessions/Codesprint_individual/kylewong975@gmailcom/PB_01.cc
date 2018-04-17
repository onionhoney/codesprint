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
	int testCases;
	cin >> testCases;
	for (int x = 0; x < testCases; x++)
	{
		int length, width;
		cin >> length >> width;
		int numLines;
		cin >> numLines;
		int horiz = 0;
		int verti = 0;
		for (int x = 0; x < numLines; x++)
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 == x2)
				horiz++;
			else if (y1 == y2)
				verti++;
		}
		cout << (horiz + 1) * (verti + 1) << endl;
	}
}