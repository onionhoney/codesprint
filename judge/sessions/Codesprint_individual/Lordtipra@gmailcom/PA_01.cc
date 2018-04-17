#include <iostream>
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
}


