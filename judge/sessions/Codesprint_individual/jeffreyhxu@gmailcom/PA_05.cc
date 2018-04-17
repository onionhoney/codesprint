#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int cases;
	cin >> cases;
	for (int cas = 0; cas < cases; cas++) {
		int p, n;
		cin >> p >> n;
		int f[1000][2];
		for (int i = 0; i < p; i++) {
			cin >> f[i][0] >> f[i][1];
		}
		int b = 0;
		while (n > 0) {
			int mb = -1;
			int ib = 0;
			for (int i = 0; i < p; i++) {
				if (f[i][0] >= mb && f[i][1] > 0) {
					mb = f[i][0];
					ib = i;
				}
			}
			int u = min(n, f[ib][1]);
			if (u == 0)
				break;
			b += u*f[ib][0];
			n -= u;
			f[ib][1] -= u;
		}
		cout << b << endl;
	}
}