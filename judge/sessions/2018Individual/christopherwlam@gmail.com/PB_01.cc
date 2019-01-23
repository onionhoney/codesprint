#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	string out = "";
	int testCases;
	cin >> testCases;
	//unordered_map<int, int> inputs[3];	// value and index
	for (int i = 0; i < testCases * 3; i++)
	{
		int j = 0;
		for (; j < 100; j++)
		{
			int in;
			cin >> in;
			if (in == 1)
			{
				out += to_string(j);
				break;
			}
		}
		string discard;
		getline(cin, discard);
		if (i % 3 == 2) out += '\n';
		else out += " ";
	}

	cout << out;
}