#include <iostream>
using namespace std;
int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		int m;
		cin >> m;
		int n;
		cin >> n;
		int k;
		cin >> k;
		int h = 1;
		int v = 1;
		for (int j = 0; j < k; j++) {
			int x1, x2, y1, y2;
			cin >> x1;
			cin >> y1;
			cin >> x2; cin >> y2;
			if (x1 == x2)
				h++;
			else
				v++;
		}
		cout << (h*v) << endl;
	}
}