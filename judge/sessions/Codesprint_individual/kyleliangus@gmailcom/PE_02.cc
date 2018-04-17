#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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

int main()
{
	int tests;
	int sections;
	int steps;
	unsigned long opt[3];
	
	cin >> tests;

	for (int i = 0; i < tests; i++)
	{
		cin >> sections;

		unsigned total = 1;
		for (int i = 0; i < sections; i++)
		{
			unsigned long possible = 0;
			opt[0] = 1; opt[1] = 1; opt[2] = 2;

			cin >> steps;
			if (steps <= 2)
				possible = opt[steps];
			else
			{
				int step = 2;
				while (step != steps)
				{
					possible = opt[2] + opt[1] + opt[0];
					opt[0] = opt[1]; opt[1] = opt[2]; opt[2] = possible;
					step++;
				}
			}
			total = ((total % 10007) * (possible % 10007) % 10007);
		}
		cout << total << endl;
	}
}