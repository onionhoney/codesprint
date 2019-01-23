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
	ofstream fout;

	ios_base::sync_with_stdio(false);
	fin.tie(NULL);

	fin.open("1A.in");
	fout.open("1A.out");
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
			maxPlayerIndex = max(0, (int)players.size() - 1);
			minPlayerIndex = 0;

			maxPingIndex = max(0, (int)pings.size() - 1);
			minPingIndex = 0;

			if (players.size() == 0 || pings.size() == 0) {
				break;
			}

			if (players[maxPlayerIndex] > pings[maxPingIndex]) {
				totalUnhappiness += players[maxPlayerIndex];

				players[maxPlayerIndex]--;
				pings[minPingIndex]--;
			}
			else if (players[maxPlayerIndex] < pings[maxPingIndex]) {
				totalUnhappiness += pings[maxPingIndex];

				pings[maxPingIndex]--;
				players[minPlayerIndex]--;
			}
			else {
				if (pings[minPingIndex] < players[minPlayerIndex]) {
					totalUnhappiness += players[maxPlayerIndex];

					players[maxPlayerIndex]--;
					pings[minPingIndex]--;
				}
				else {
					
					totalUnhappiness += pings[maxPingIndex];

					pings[maxPingIndex]--;
					players[minPlayerIndex]--;
				}
			}

			while (players.size() != 0 && players[0] == 0) {
				players.erase(players.begin());
			}
			while (pings.size() != 0 && pings[0] == 0) {
				pings.erase(pings.begin());
			}

			sort(players.begin(), players.end());
			sort(pings.begin(), pings.end());
		}

		cout << totalUnhappiness << endl;
	}
}