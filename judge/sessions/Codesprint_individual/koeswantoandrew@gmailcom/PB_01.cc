#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <stdlib.h>
#include <cassert>
#include <algorithm>
using namespace std;

//codesprint A //remember to cout << newline

int main() {
	int testCases;
	cin >> testCases;

	for (int a = 0; a < testCases; a++) {
		int rows;
		int cols;
		cin >> rows >> cols;

		int lines;
		cin >> lines;
		vector<int> horizontal;
		vector<int> vertical;

		for (int i = 0; i < lines; i++) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;

			if (x1 == x2 && x1 != 0) {
				horizontal.push_back(x1);
			}
			else if (y1 == y2 && y1 != 0) {
				vertical.push_back(y1);
			}
		}

		unique(horizontal.begin(), horizontal.end());
		unique(vertical.begin(), vertical.end());

		cout << (horizontal.size() + 1)*(vertical.size() + 1) << endl;

	}

}