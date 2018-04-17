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

	int flowerNumber[100];
	int maxDrawn[100];
	int maxBeauty = 0;

	int beauty;
	int number;

	int totalBeauty = 0;

	for (int i = 0; i < testCases; i++)
	{
		cin >> flowerNumber[i];
		cin >> maxDrawn[i];
		for (int j = 0; j < flowerNumber[i]; j++)
		{
			cin >> beauty >> number;
			if (number < maxDrawn[i])
			{
				totalBeauty += number*beauty;
				maxDrawn[i] -= number;
			}
			else
			{
				totalBeauty += maxDrawn[i] * beauty;
				break;
			}
		}
		cout << totalBeauty << endl;
		totalBeauty = 0;
	}
	return -1;
}