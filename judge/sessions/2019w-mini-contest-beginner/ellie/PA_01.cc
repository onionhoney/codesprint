#include <iostream>
using namespace std;

int main() {
	int t, n;
	int draw, x1, y1, x2, y2;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int area = 0;
		for (int j = 0; j < n; j++) {
			cin >> draw >> x1 >> y1 >> x2 >> y2;
			
			if (draw)
				area += (x2 - x1) * (y2 - y1);
			else 
				area -= (x2 - x1) * (y2 - y1);
		}
		cout << area << endl;
	}
}