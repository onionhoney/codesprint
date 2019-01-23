#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <queue>
#include <map>
#include <iomanip>

#define ll long long

using namespace std;


int main() {
	/*
	ifstream fin;
	ofstream cout;

	ios_base::sync_with_stdio(false);
	fin.tie(NULL);

	fin.open("1A.in");
	cout.open("1A.out");
	*/

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n, p, q;
		cin >> n >> p >> q;

		vector<int> players(p);
		vector<int> pings(q);

		for (int i = 0; i < p; i++)
			cin >> players[i];

		for (int i = 0; i < q; i++)
			cin >> pings[i];

		sort(players.begin(), players.end());
		sort(pings.begin(), pings.end());

		int maxPlayerIndex = p - 1;
		int minPlayerIndex = 0;

		int maxPingIndex = q - 1;
		int minPingIndex = 0;

		int totalUnhappiness = 0;

		for (int i = 0; i < n; i++) {
			if (players[maxPlayerIndex] > pings[maxPingIndex]) {
				totalUnhappiness += players[maxPlayerIndex];

				players[maxPlayerIndex]--;
				pings[minPingIndex]--;
			}
			else {
				totalUnhappiness += pings[maxPingIndex];

				pings[maxPingIndex]--;
				players[minPlayerIndex]--;
			}

			if (minPlayerIndex == maxPlayerIndex && players[minPlayerIndex] == 0)					// boundary cases (when all elements have been used)
				break;

			if (minPingIndex == maxPingIndex && pings[minPingIndex] == 0)
				break;

			if (maxPlayerIndex == 0 || players[maxPlayerIndex] > players[maxPlayerIndex - 1])
				maxPlayerIndex = p - 1;
			else if (players[maxPlayerIndex] < players[maxPlayerIndex - 1])							// adjustment of indices
				maxPlayerIndex--;

			if (maxPingIndex == 0 || pings[maxPingIndex] > pings[maxPingIndex - 1])
				maxPingIndex = q - 1;
			else if (pings[maxPingIndex] < pings[maxPingIndex - 1])
				maxPingIndex--;

			if (players[minPlayerIndex] == 0)
				minPlayerIndex++;
			if (pings[minPingIndex] == 0)
				minPingIndex++;

		}

		cout << totalUnhappiness << endl;
	}
}