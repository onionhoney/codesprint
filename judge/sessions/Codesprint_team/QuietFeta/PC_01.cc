#include<iostream>
#include <string>
#include<algorithm>
using namespace std;

int main() {
	int num = 0;
	cin >> num;
	
	
	int Re[100];
	for (int i = 0; i < 100; i++) {
		Re[i] = -1;
	}
	int lamp[2][1000];
	
	for (int i = 0; i < num; i++) {
		int d, n, l;
		cin >> d >> n >> l;
		for (int t = 0; t < n; t++) {
			double dis;
			int p;
			cin >> dis >> p;
			lamp[0][t] = dis;
			lamp[1][t] = p;
		}
		for (int j = l; j >= 1; j--) {
				
			double time = 0;
			int flag = 0;
			for (int k = 0; k < n; k++){
				
				
				time = lamp[0][k] / j;
				//int ti = dis / j;
				int in = time/lamp[1][k];
				if (in % 2 == 0) {
					continue;
				}
				else {
					flag = 1;
				}
			}
			if (flag == 0) {
				Re[i] = j;
				break;
			}
			//cout << Re[i] << endl;
		}		
	}
	for (int i = 0; i < num; i++) {
		cout << Re[i] << endl;
	}
}