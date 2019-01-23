#include <iostream>
#include <vector>

using namespace std;

int main () {
	int cases; cin >> cases;
	for (int i = 0; i < cases; i++) {
		vector<int> answers;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 10; k++) {
				int guess;
				cin >> guess;
				if (guess == 1) {
					answers.push_back(k);
				}
			}
			cout << endl;
		} 
		for (int j = 0; j < 3; j++) {
			cout << answers[j] << " ";
		}
		cout << endl;
	}

}
