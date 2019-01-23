#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long mod = 100000007;

int main() {
	long long n;
	cin >> n;
	vector<long long> dp(100000);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2 ; i < 100000; i++) {
		dp[i] = (dp[i-1] + dp[i-2]) % mod;
	}

	while (n--) {
		long long ai;
		cin >> ai;
		cout << dp[--ai] << "\n";
	}
}