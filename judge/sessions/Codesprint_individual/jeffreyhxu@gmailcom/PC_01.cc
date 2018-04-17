#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	for (int cas = 0; cas < cases; cas++) {
		int m, n, a, b;
		cin >> m >> n >> a >> b;
		int arr[100][100];
		cin.ignore(1000, '\n');
		for (int i = 0; i < m; i++) {
			string in;
			getline(cin, in);
			for (int j = 0; j < n; j++) {
				if (in[j] == '.')
					arr[i][j] = 0;
				else
					arr[i][j] = 1;
				cout << arr[i][j];
			}
			cout << endl;
		}
		a--;
		b--;
		string path;
		for (;;) {
			arr[a][b] = 2;
			if (arr[max(0, a - 1)][b] == 1) {
				path += "U";
				a--;
			}
			else if (arr[a][min(n - 1, b + 1)] == 1) {
				path += "R";
				b++;
			}
			else if (arr[min(m - 1, a + 1)][b] == 1) {
				path += "D";
				a++;
			}
			else if (arr[a][max(0, b - 1)] == 1) {
				path += "L";
				b--;
			}
			else break;
		}
		cout << path << endl;
	}
}