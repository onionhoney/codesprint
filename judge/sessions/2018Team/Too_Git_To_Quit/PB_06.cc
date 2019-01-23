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
	int* unhappiness = new int[testCases];
	for (int i = 0; i < testCases; i++)
	{
		int numPings, numTeammates, pingTypes;
		cin >> numPings >> numTeammates >> pingTypes;
		//cout << numPings << numTeammates << pingTypes;

		vector<int> instability(numTeammates);
		for (int i = 0; i < numTeammates; i++)
		{
			int in;
			cin >> in;
			instability.push_back(in);
		}
		//sort(instability.begin(), instability.end());

		vector<int> pingStrength(pingTypes);
		for (int i = 0; i < pingTypes; i++)
		{
			int in;
			cin >> in;
			pingStrength.push_back(in);
		}
		//sort(pingStrength.begin(), pingStrength.end());


		vector<int>::iterator pingSearch = find(pingStrength.begin(), pingStrength.end(), 0);
		while (pingSearch != pingStrength.end())
		{
			pingStrength.erase(pingSearch);
			pingSearch = find(pingStrength.begin(), pingStrength.end(), 0);
		}

		vector<int>::iterator instSearch = find(instability.begin(), instability.end(), 0);
		while (instSearch != instability.end())
		{
			instability.erase(instSearch);
			instSearch = find(instability.begin(), instability.end(), 0);
		}

		unhappiness[i] = 0;
		for (; numPings > 0; numPings--)
		{
			vector<int>::iterator pingMax = max_element(pingStrength.begin(), pingStrength.end());
			vector<int>::iterator instMax = max_element(instability.begin(), instability.end());
			vector<int>::iterator pingMin = min_element(pingStrength.begin(), pingStrength.end());
			vector<int>::iterator instMin = min_element(instability.begin(), instability.end());

			if (pingMax == pingStrength.end() || instMax == instability.end())
			{
				// error, no elements in either of them, can't proceed
				break;
			}
			if (*pingMax > *instMax)
			{
				instMax = min_element(instability.begin(), instability.end());
			}
			else if (*pingMax < *instMax){
				pingMax = min_element(pingStrength.begin(), pingStrength.end());
			}
			else {
				if (*pingMin < *instMin)
					pingMax = pingMin;
				else
					instMax = instMin;
			}
			//cout << "adding " << *instMax << " from instability and " << *pingMax << " from pings" << endl;
			unhappiness[i] += max(*instMax, *pingMax);
			(*instMax)--;
			if (*instMax == 0) instability.erase(instMax);
			(*pingMax)--;
			if (*pingMax == 0) pingStrength.erase(pingMax);
		}
	}

	
	for (int i = 0; i < testCases; i++)
	{
		cout << unhappiness[i] << endl;
	}
	/*
	Test cases
	8
	0 4 4
	10 8 1 4
	2 7 11 1
	5 0 4
	2 7 11 1
	5 1 0
	10
	10 3 1
	1 2 3
	0
	2 2 2
	6 6
	0 0
	5 4 4
	10 8 1 4
	2 7 11 1
	10 3 1
	1 2 3
	6
	2 2 2
	6 6
	3 6
	
	1
	5 1 0
	10 8 1 4
	

	1
	10 3 1
	1 2 3
	0

	1
	5 0 4
	2 7 11 1

	1
	2 2 2
	6 6
	0 0

	1
	10 3 1
	1 2 3
	1
	*/
}