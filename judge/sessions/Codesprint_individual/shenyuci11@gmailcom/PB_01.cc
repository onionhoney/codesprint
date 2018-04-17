#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

using namespace std;

//always include endl with cout <<

int main()
{
	int testCases;
	cin >> testCases;

	int length;
	int width;
	int lines;
	int sections;

	int x1, y1, x2, y2;
	int horizontal = 1;
	int vertical = 1;

	for (int i = 0; i < testCases; i++)
	{
		horizontal = 0;
		vertical = 0;
		cin >> length >> width;
		cin >> lines;
		for (int j = 0; j < lines; j++)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 == x2)
				horizontal++;
			if(y1 == y2)
				vertical++;
		}
		sections = horizontal*vertical;
		cout << sections << endl;
	}
	return 0;
}