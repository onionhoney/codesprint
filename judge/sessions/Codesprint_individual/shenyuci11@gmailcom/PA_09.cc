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

	int flowerNumber;
	int maxDrawn;

	int beauty;
	int number;

	bool done = false;

	int totalBeauty = 0;

	for (int i = 0; i < testCases; i++)
	{
		totalBeauty = 0;
		cin >> flowerNumber >> maxDrawn;
		for (int j = 0; j < flowerNumber; j++)
		{
			cin >> beauty >> number;
			if (number < maxDrawn)
			{
				totalBeauty += number*beauty;
				maxDrawn -= number;
			}
			else if (!done)
			{
				totalBeauty += maxDrawn * beauty;
				done = true;
			}
		}
		cout << totalBeauty << endl;
	}
	return -1;
}