#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string out = "";
	int testCases;
	cin >> testCases;
	//unordered_map<int, int> inputs[3];	// value and index
	int* finalCount = new int[testCases];
	for (int i = 0; i < testCases; i++)
	{
		int numShots, calibrateNum;
		cin >> numShots >> calibrateNum;
		string shotHistory;
		cin.ignore(10000, '\n');
		getline(cin, shotHistory);
		//cout << shotHistory;

		finalCount[i] = 0;
		int consecCount = 1;
		char prev = shotHistory[0];
		for (int j = 1; j < numShots; j++)
		{
			if (shotHistory[j] == prev) consecCount++;
			else consecCount = 1;
			prev = shotHistory[j];
			if (consecCount == calibrateNum)
			{
				if (shotHistory[j] == 'R') finalCount[i]--;
				else if (shotHistory[j] == 'L') finalCount[i]++;
				consecCount = 0;
			}
		}
	}

	for (int i = 0; i < testCases; i++)
	{
		cout << finalCount[i] << endl;
	}
}