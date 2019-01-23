#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

/*vector<vi>::iterator find(vector<vi> room, int num) {
	for (vector<vi>::iterator it = room.begin(); it != room.end(); it++) {
		for (vi::iterator itt = (*it).begin(); itt != (*it).end(); itt++) {
			if (*itt == num) return it;
		}
	}
}

vector<vi>::iterator merge(vector<vi> room, vector<vi>::iterator first, vector<vi>::iterator second) {
	vi tmp(*first);
	tmp.insert((*second).end(), (*second).begin(), (*second).end());

	room.erase(first);
	room.erase(second);
	room.push_back(tmp);
	return room.end() - 1;
}*/

int main() {
	int cases; cin >> cases;
	vi ans(cases);
	for (int z = 0; z < cases; z++) {
		int numDistricts = 0; int numContestants = 0;
		cin >> numDistricts >> numContestants;
		vi pop(numDistricts);
		for (int i = 0; i < numDistricts; i++) {
			cin >> pop[i];
		}
		vector<vi> dp(numDistricts, vi(numContestants));
		for (int i = 0; i < numDistricts; i++) {
			dp[i][0] = 0;
			for(int j = 0; j < numContestants; j++) {
				dp[i][numContestants - 1] = -1;
			}
		}
		for (int i = 1; i < numContestants; i++) {
			dp[0][i] = 0;
			for (int j = 2; j < numDistricts; j++) {
				long long test = -1;
				if (dp[j - 2][i - 1] != -1) test = dp[j - 2][i - 1] + pop[j - 2];
				dp[j][i] = max(dp[j - 1][i], test);
			}
		}
		long long maxval = 0;
		for (int i = 0; i < numDistricts; i++) {
			if(dp[i][numContestants - 1] != -1) maxval = max(maxval, dp[i][numContestants-1]+ pop[i]);
		}
		ans[z] = maxval;
	}
	for (int i = 0; i < cases; i++) {
		cout << ans[i] << endl;
	}
	/*int cases; cin >> cases;{

	vi ans(cases);
	for (int z = 0; z < cases; z++) {
		int maxtime;
		int vr; cin >> vr;
		int stop; cin >> stop;
		int stair; cin >> stair;
		int floors; cin >> floors;
		vi dest(floors);
		for (int i = 0; i < floors; i++) {
			dest[i] = 0;
		}

		int ppl; cin >> ppl;
		int want = 0;
		int maxelv = 0;
		for (int i = 0; i < ppl; i++) {
			int m; cin >> m;
			dest[i - 1] = 1;
			maxelv = (i - 1)*vr + stop;
		}
		int maxstair = 0;
		for (int i = 0; i < floors; i++) {
			if (dest[i] != 0) {
				if (maxelv + stop > (i - 1)*stair) {

				} 
				sta
			}
		}


	}*/
	

	/*
	int cases; cin >> cases;
	vi ans(cases);
	for (int z = 0; z < cases; z++) {
		int n; cin >> n;
		int l; cin >> l;
		int k; cin >> k;
		vector<vi> rooms(n);
		for (int i = 0; i < n; i++) {
			rooms[i] = vi(1);
			rooms[i][0] = i+1;
		}
		for (int i = 0; i < l; i++) {
			int first; cin >> first;
			int second; cin >> second;
			merge(rooms, find(rooms, first), find(rooms, second));
		}
		vector<vi>::iterator largest;
		int size = 0;
		for (vector<vi>::iterator it = rooms.begin(); it != rooms.end(); it++) {
			if ((*it).size() > size) {
				size = (*it).size();
				largest = it;
			}
		}
		for (int i = 0; i < k; i++) {
			vector<vi>::iterator second;
			size = 0;
			for (vector<vi>::iterator it = rooms.begin(); it != rooms.end(); it++) {
				if ((*it).size() > size && it != largest) {
					size = (*it).size();
					second = it;
				}
			}
			largest = merge(rooms, largest, second);
		}
		int sum = 0;
		for (vector<vi>::iterator it = rooms.begin(); it != rooms.end(); it++) {
			sum += (*it).size()*((*it).size() - 1) / 2;
		}
		cout << size;
	}
	*/
	/*
	int cases; cin >> cases;
	for (int i = 0; i < cases; i++) {
		vi ans(3);
		int t;
		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 100; j++) {
				cin >> t;
				if (t == 1) {
					ans[k] = j;
				}
			}
		}
		
		for (int l = 0; l < cases; l++) {
			cout << ans[l] << endl;
		}
	}
	*/


	/*vi a(n);
	ll maxx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	vi dp(maxx + 2);
	const ll MOD = 100000007LL;
	dp[1] = 1; dp[2] = 1;
	for (int i = 3; i <= maxx; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}*/

	return 0;
}
/*
0 0 0 0 0 0 0 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2*/