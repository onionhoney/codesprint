#include <iostream>
using namespace std;
int main() {
	int cases;
	cin >> cases;
	for (int cas = 0; cas < cases; cas++) {
		int d, n, r;
		cin >> d >> n >> r;
		int* l = new int[n];
		int* p = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> l[i] >> p[i];
		}
		bool nope = true;
		for (int i = r; i >= 0; i--) {
			bool yes = true;
			for (int j = 0; j < n; j++) {
				if (l[j] / (i*p[j]) % 2 != 0) {
					yes = false;
					break;
				}
			}
			if (yes) {
				cout << i << endl;
				nope = false;
				break;
			}
		}
		if (nope)
			cout << -1 << endl;
	}
}