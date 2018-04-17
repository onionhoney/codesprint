#include <string>
#include <iostream>

using namespace std;

int main() {
	int t; //number of test cases
	cin >> t;
	cout << endl;
	int* foo = new int[t];
	for (int i = 0; i < t;i++) {
		int totbeauty = 0;
		int typeflowers;
		int candraw;
		cin >> typeflowers;
		cin >> candraw;
		cout << endl;
		for (int q = 0; q < typeflowers; q++) {
			bool broke = false;
			if (broke) break;
			int beauty;
			int boredom;
			cin >> beauty;
			cin >> boredom;
			while (candraw != 0 && boredom != 0) {
				if (candraw == 0) {
					break;
				}
				totbeauty += beauty;
				boredom--;
				candraw--;
			}
		}
		foo[i] = totbeauty;
	}
	for (int i = 0;i < t;i++) {
		cout << *(foo + i) << endl;
	}
	cout << endl;
}