#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	int t, n;
	int draw, x1, y1, x2, y2;
	cin >> t;

	
	
	for (int i = 0; i < t; i++) {
		vector<vector<int>> paper(100, vector<int>(100, 0));
		cin >> n;
		int area = 0;
		for (int j = 0; j < n; j++) {
			cin >> draw >> x1 >> y1 >> x2 >> y2;

			for (int y = y1; y < y2; y++)
				for (int x = x1; x < x2; x++)
					paper[y][x] = draw;

		}
		int count = 0;
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				if (paper[i][j] == 1)
					count++;
		cout << count << endl;
	}
	
	
}