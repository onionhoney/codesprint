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

int main() {
	
	int cases; cin >> cases;
	vi ans(cases);
	for (int i = 0; i < cases; i++) {
		int max = 0;
		int jump; cin >> jump;
		int amax; cin >> amax;
		int bmax; cin >> bmax;
		vi a(amax);
		vi b(bmax);
		for (int j = 0; j < amax; j++) {
			cin >> a[j];
		}
		for (int j = 0; j < bmax; j++) {
			cin >> b[j];
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		vi::iterator ait = a.begin();
		vi::reverse_iterator bit = b.rbegin();
		while (ait != a.end() && bit != b.rend()) {
			int m = *ait + *bit;
			if (m > jump) {
				++bit;
				continue;
			}
			if (m > max) {
				max = m;
			}
			ait++;
		}
		ans[i] = max;
	}


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
	for (int i = 0; i < cases; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}