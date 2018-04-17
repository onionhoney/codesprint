/*#include <iostream>
using namespace std;

int main() {
	int *testCases = new int[2], **beauty, **number, *types, *battery;
	cin >> testCases[0];
	beauty = new int*[testCases[0]];
	number = new int*[testCases[0]];
	types = new int[testCases[0]];
	battery = new int[testCases[0]];
	for (int j = 0; j < testCases[0]; j++) {
		cin >> types[j];
		cin >> battery[j];
		beauty[j] = new int[types[j]];
		number[j] = new int[types[j]];
		for (int i = 0; i < types[j]; i++)
		{
			cin >> beauty[j][i];
			cin >> number[j][i];
		}
	}

	int flowerDrawn, totalBeauty;
	for (int i = 0; i < testCases[0]; i++) {
		flowerDrawn = 0;
		totalBeauty = 0;
		for (int j = 0; j < types[i]; j++) {
			if (number[i][j] + flowerDrawn > battery[i])
				number[i][j] = battery[i] - flowerDrawn;
			flowerDrawn += number[i][j];
			totalBeauty += number[i][j] * beauty[i][j];
		}
		cout << totalBeauty << endl;
	}
}*/

#include <iostream>
using namespace std;

int main() {
	int *testCases = new int[2], *width, * length, * lines,  xLines,  yLines, * ans;
	cin >> testCases[0];
	width = new int[testCases[0]];
	length = new int[testCases[0]];
	lines = new int[testCases[0]];
	ans = new int[testCases[0]];
	for (int i = 0; i < testCases[0]; i++) {
		xLines = yLines = 0;
		cin >> width[i];
		cin >> length[i];
		cin >> lines[i];
		for (int j = 0; j < lines[i]; j++) {
			int x1, y1, x2, y2;
			cin >> x1;
			cin >> y1;
			cin >> x2;
			cin >> y2;
			if (x1 - x2 == 0)
				yLines++;
			else xLines++;
		}
		ans[i] = (xLines + 1) * (yLines + 1);
	}
	for (int i = 0; i < testCases[0]; i++) {
		cout << ans[i] << endl;
	}
}