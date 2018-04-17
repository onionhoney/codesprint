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
		int types;
		int number;
		int total = 0;
		cin >> types >> number;

		for (int i = 0; i < types; i++) {
			int value;
			int limit;
			cin >> value >> limit;

			int amount = min(number, limit);
			number -= amount;
			total += value * amount;

			if (number == 0) {
				break;
			}
		}

		cout << total << endl;

	}
}