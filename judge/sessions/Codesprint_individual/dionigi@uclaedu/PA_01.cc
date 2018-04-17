/* @file main.cpp
NOTES
Print a '\n' after every answer to cout
*/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

const int MAX_TESTS = 100;
const int MAX_FLOWERS = 1000;
const int MAX_BATTERY = 50000;

void test();
int getNumber();

int main()
{
	test();
}
void test()
{
	int results[MAX_TESTS];
	int t = 0, flowerTypes, batteryLife, flBeauty[MAX_FLOWERS], flLimit[MAX_FLOWERS];
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> flowerTypes >> batteryLife;
		for (int i = 0; i < flowerTypes; i++)
		{
			cin >> flBeauty[i] >> flLimit[i];
		}

		int curFlower = 0, count = 0;
		while (batteryLife > 0 && curFlower < flowerTypes)
		{
			if (flLimit[curFlower] > 0) {
				count += flBeauty[curFlower];
				flLimit[curFlower]--;
				batteryLife--;
			}
			else
				curFlower++;
		}
		results[i] = count;
	}

	for (int i = 0; i < t; i++)
	{
		cout << results[i] << '\n';
	}
}

int getNumber()
{
	int a, b;
	cin >> a >> b;
	return (a + b);
}
