#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	int cases;
	cin >> cases;
	for (int cas = 0; cas < cases; cas++) {
		int r;
		cin >> r;
		int gain = -3;
		int total = r*2+1;
		for (int y = 1; y <= r; y++) {
			double x = sqrt(pow(r, 2) - pow(y, 2));
			total += 2*(floor(x) * 2 + 1);
			if (x - floor(x) >= 0.5) {
				gain += 2;
			}
		}
		cout << max(total, total + gain) << endl;
	}
}