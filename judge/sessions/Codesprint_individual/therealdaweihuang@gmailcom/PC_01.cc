#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	string path[100];

	for (int tr = 0; tr < t; tr++) {
		
		int m, n, a, b;
		cin >> m >> n;
		cin >> a >> b;
		a--;
		b--;


		char map[100][100];

		for (int j = 0; j < m; j++) {
			string row;
			cin >> row;
			for (int i = 0, len = row.length(); i < len; i++) {
				map[j][i] = row[i];
			}
		}

		bool nearby = true;

		while (nearby) {
			nearby = false;
			
			if (a - 1 >= 0 && map[a - 1][b] == '#') {
				nearby = true;
				a--;
				map[a - 1][b] = 'S';
				path[t] += 'U';
			}

			if (a + 1 < m && map[a + 1][b] == '#') {
				nearby = true;
				a++;
				map[a + 1][b] = 'S';
				path[t] += 'D';
			}

			if (b - 1 >= 0 && map[a][b - 1] == '#') {
				nearby = true;
				b--;
				map[a][b - 1] = 'S';
				path[t] += 'L';
			}

			if (b + 1 < n && map[a][b + 1] == '#') {
				nearby = true;
				b++;
				map[a][b + 1] = 'S';
				path[t] += 'R';
			}
		}
	}
	for (int i = 0; i < t; i++) {
		cout << path[t];
	}
}