#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <map>

#define ll long long

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l, k;
	cin >> n >> l >> k;

	vector<vector<int>> adj_list(n + 1);

	for (int i = 0; i < l; i++) {
		int a, b;
		cin >> a >> b;

		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	vector<bool> used(n + 1);
	vector<int> loop_counts;
	
	for (int i = 1; i <= n; i++) {
		int count = 0;
		queue<int> q;

		if (used[i]) continue;

		q.push(i);
		used[i] = true;
		
		while (!q.empty()) {							// bfs
			int working = q.front();
			q.pop();

			for (int a : adj_list[working]) {
				if (used[a]) continue;

				q.push(a);
				used[a] = true;
			}

			count++;
		}

		loop_counts.push_back(count);
	}

	sort(loop_counts.begin(), loop_counts.end());

	int merged = 0;
	long long total = 0;
	k++;

	for (int i = loop_counts.size() - 1; i >= 0; i--) {
		if (k > 0) {
			merged += loop_counts[i];
			k--;
		}
		else {
			total += loop_counts[i] * (loop_counts[i] - 1) / 2;
		}
	}

	total += merged * (merged - 1) / 2;

	cout << total << endl;

}