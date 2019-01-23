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
	ifstream fin;
	ofstream fout;

	ios_base::sync_with_stdio(false);
	fin.tie(NULL);

	fin.open("1C.in");
	fout.open("1C.out");

	int tc;
	fin >> tc;

	for (int i = 0; i < tc; i++) {
		int n, s;
		fin >> n >> s;

		fout << setprecision(2) << fixed;

		vector<double> chances(n);
		vector<int> damages(n);

		for (int i = 0; i < n; i++) {
			fin >> chances[i];
		}

		for (int i = 0; i < n; i++) {
			fin >> damages[i];
		}

		vector<vector<double>> dp(s + 1, vector<double>(n + 1));
		dp[0][0] = 1.0;

		for (int i = 0; i < s; i++) {
			for (int j = 0; j < n + 1; j++) {
				if (j == n) {
					dp[i + 1][j] += dp[i][j];
					continue;
				}

				if (i < n) {
					if (i + 1 + damages[i] <= s)
						dp[i + 1 + damages[i]][j] += dp[i][j] * chances[i];
					else
						dp[s][j] += dp[i][j] * chances[i];

					dp[i + 1][j + 1] += dp[i][j] * (1 - chances[i]);
				}
				else {
					dp[i + 1][j] += dp[i][j];
				}
			}
		}

		double expectation = 0;
		double totalPerc = 0;

		for (int i = 0; i < n + 1; i++) {
			expectation += dp[s][i] * i;
		}

		fout << (int)expectation << endl;
	}
}