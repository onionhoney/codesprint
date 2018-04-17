#include <iostream>
using namespace std;

bool inRange(int, int, int, int);

int main() {
	int t;
	cin >> t;
	int *output = new int[t];
	bool arena[1000][1000];

	for (int v = 0; v < t; v++) {
		int m, n;
		cin >> m >> n;
		m; n;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				arena[i][j] = false;
			}
		}

		int k;
		cin >> k;

		int* xpos = new int[k];
		int* ypos = new int[k];

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			arena[x][y] = true;
			xpos[i] = x;
			ypos[i] = y;
		}

		int count = 0;
		for (int i = 0; i < k; i++) {

			for (int g = -1; g <= 1; g++) {
				for (int h = -1; h <= 1; h++) {
					int a = xpos[i] + g, b = ypos[i] + h;
						if (inRange(a, b, m, n)) {
							if (!arena[a][b])
								count++;
						}
				}
			}

		}
		output[v] = count;
		


	}

	for (int i = 0; i < t; i++) {
		cout << output[i] << endl;
	}
}

bool inRange(int a, int b, int m, int n) {
	return (a >= 0 && a < m && b >= 0 && b < n);
}