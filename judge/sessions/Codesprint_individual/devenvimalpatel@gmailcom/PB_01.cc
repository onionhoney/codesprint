#include <string>
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int boxes = 0;
		int xlines = 1;
		int ylines = 1;
		int m;
		int n;
		cin >> m;
		cin >> n;
		int k;
		cin >> k;
		for (int q = 0;q < k;q++) {
			int x1;
			int x2;
			int y1;
			int y2;
			cin >> x1;
			cin >> y1;
			cin >> x2;
			cin >> y2;
			if (x1 == x2) xlines++;
			if (y1 == y2) ylines++;
		}
		boxes = xlines *ylines;
		cout << boxes << endl;
	}
}