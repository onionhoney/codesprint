#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	//string out = "";
	int testCases;
	cin >> testCases;
	//unordered_map<int, int> inputs[3];	// value and index
	double* expected = new double[testCases];
	for (int k = 0; k < testCases; k++)
	{
		int numBots, seconds;
		cin >> numBots >> seconds;
		vector<double> chanceExplode;
		for (int i = 0; i < numBots; i++)
		{
			double in;
			cin >> in;
			chanceExplode.push_back(in);
		}

		vector<int> assemblyLine;
		for (int i = 0; i < numBots; i++)
		{
			int in;
			cin >> in;
			assemblyLine.push_back(in);	// the items in the assembly line represent i-th's robot's blast radius
		}
		
		expected[k] = numBots;
		// Factory start. 1 bot per second
		for (int sec = 1; sec < seconds; sec++)
		{

			for (int i = 0; i < numBots; i++)
			{
				chanceExplode[i] *= chanceExplode[i];
			}
			
		}
		for (int i = 0; i < numBots; i++)
		{
			expected[k] -= chanceExplode[i] * (1 + assemblyLine[i]);
		}
	}


	for (int i = 0; i < testCases; i++)
	{
		cout << expected[i] << endl;
	}

}