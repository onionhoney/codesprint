#include <iostream>
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
				if (f[i][0] >= mb) {
					mb = f[i][0];
					ib = i;
				}
			}
			int u;
			if (n < f[ib][1])
				u = n;
			else
				u = f[ib][1];
			b += u*f[ib][0];
			n -= u;
		}
		cout << b << endl;
	}
}