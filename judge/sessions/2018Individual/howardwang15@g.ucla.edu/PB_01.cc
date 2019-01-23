#include <iostream>

using namespace std;

int main () {
	int cases; cin >> cases;
	for (int i = 0; i < cases; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 10; k++) {
				int guess;
				cin >> guess;
				if (guess == 1) {
					cout << k << " " << endl;
					break;
				}
			}
		} 
		cout << endl;
	}

}
