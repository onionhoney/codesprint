#include <stdio.h>
#include <iostream>
//#include <string>

using namespace std;
int tests = 0;

int main () {
    int score = 0;
    int flowersDrawn = 0;
    cin >> tests; //read first line to get number of tests
	for (int i = 0; i < tests; i++) {
		int p = 0;
		int n = 0;
		cin >> p >> n; //in next line record p and n
		for (int j = 0; j < p; j++){
			int b = 0;
			int max = 0;
			cin >> b >> max; //read beauty and max number
			for (int m = 0; m < max; m++) {
				if (flowersDrawn < n){
					score += b;
					flowersDrawn++;
				}
			}
		}
	}
	cout << score+"\n";
	return 0;
}
