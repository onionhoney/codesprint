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
}

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

#include <iostream>
#include <string>
using namespace std;

int main() {
	int *testCases = new int[2], *row, *col, *a, *b;
	char ***map;
	cin >> testCases[0];
	row = new int[testCases[0]];
	col = new int[testCases[0]];
	a = new int[testCases[0]];
	b = new int[testCases[0]];
	map = new char**[testCases[0]];
	for (int i = 0; i < testCases[0]; i++) {
		cin >> row[i];
		cin >> col[i];
		cin >> a[i];
		a[i] -= 1;
		cin >> b[i];
		b[i] -= 1;
		map[i] = new char*[row[i]];
		for (int j = 0; j < row[i]; j++) {
			map[i][j] = new char[col[i]];
			for (int k = 0; k < col[i]; k++) {
				cin >> map[i][j][k];
			}
		}

	}
	string str;
	bool endPath;
	for (int i = 0; i < testCases[0]; i++) {
		str = "";
		endPath = false;
		while (!endPath) {
			if (a[i] - 1 >= 0)
				if (map[i][a[i] - 1][b[i]] == '#') {
					map[i][a[i] - 1][b[i]] = '.';
					a -= 1;
					str += "U";
				}
			else if (a[i] + 1 < row[i])
				if (map[i][a[i] + 1][b[i]] == '#') {
					map[i][a[i] + 1][b[i]] = '.';
					a += 1;
					str += "D";
				}
			else if (b[i] + 1 < col[i])
				if (map[i][a[i]][b[i] + 1] == '#') {
					map[i][a[i]][b[i] + 1] = '.';
					b += 1;
					str += "R";
				}
			else if (b[i] - 1 >= 0)
				if (map[i][a[i]][b[i] - 1] == '#') {
					map[i][a[i]][b[i] - 1] = '.';
					b -= 1;
					str += "L";
				}
			else
				endPath = true;
		}
		cout << str << endl;
		
	}
} 

#include <iostream>
#include <string>
using namespace std;

int main() {
	int *testCases = new int[2];
	cin >> testCases[0];
	for (int i = 0; i < testCases[0];i++) {
		int dist, num, limit;
		cin >> dist;
		cin >> num;
		cin >> limit;
		int* templocs = new int[num];
		int* locs = new int[num];
		int* temppers = new int[num];
		int* pers= new int[num];
		for (int j = 0; j < num; j++) {
			cin >> templocs[j];
			cin >> temppers[j];
		}

		int GCF;

		int min = 100000, per = 0; // organizes by distance
		for (int j = 0; j < num; j++) {
			min = 100000;
			for (int k = j; k < num; k++) {
				if (templocs[k] < min) {
					min = templocs[k];
					per = temppers[k];
				}
			}
			locs[j] = min;
			pers[j] = per;
		}
	}
} */

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

int main() {

	int num_tests;
	cin >> num_tests;
	cin.ignore(1000, '\n');

	int* distinct = new int[num_tests + 1];

	for (int a = 0; a < num_tests; a++) {
		string input;
		string cleaned;
		string history;
		int inc = 0;
		getline(cin, input);

		for (int b = 0; b < input.length(); b++) {
			if (!isdigit(input[b])) {
				cleaned += tolower(input[b]);
			}
		}

		for (int b = 0; b < cleaned.length(); b++) {
			if (history.find(cleaned[b]) == history.npos) {
				inc++;
				history += cleaned[b];
			}
		}
		distinct[a] = inc;
	}
	for (int a = 0; a < num_tests; a++) {
		if (distinct[a] % 2 == 1)
			cout << "TRASH TALK THE USER" << endl;
		else
			cout << "INVITE TO PARTY" << endl;
	}
}