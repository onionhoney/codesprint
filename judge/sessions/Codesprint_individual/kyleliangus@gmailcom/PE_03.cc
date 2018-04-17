#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<unsigned long, unsigned long> opt;

int maxLong(long a, long b)
{
	if (a > b)
		return a;
	return b;
}

int minLong(long a, long b)
{
	if (a < b)
		return a;
	return b;
}

unsigned long findSteps(unsigned long l)
{
	if (opt.find(l) == opt.end())
	{
		opt[l] = findSteps(l - 1) + findSteps(l - 2) + findSteps(l - 3);
	}
	return opt[l];
}

int main()
{
	int tests;
	int sections;
	int steps;
	
	opt[0] = 1;
	opt[1] = 1;
	opt[2] = 2;
	opt[3] = 4;
	
	cin >> tests;

	for (int i = 0; i < tests; i++)
	{
		cin >> sections;

		unsigned total = 1;
		for (int i = 0; i < sections; i++)
		{
			unsigned long possible = 0;
			cin >> steps;
			
			possible = findSteps(steps);

			total = ((total % 10007) * (possible % 10007) % 10007);
		}
		cout << total << endl;
	}
}