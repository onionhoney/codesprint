#include<iostream>

using namespace std;

int main() {
	int numP;
	cin >> numP;
	int MaxT, MaxB;
	int Re[100];
	
	
	for (int i = 0; i < numP; i++) {
		cin >> MaxT >> MaxB;
		int k = MaxB;
		int t = MaxT;
		int tBeauty = 0;
		int beauty = 0;
		int num = 0;
		int flag = 0;
		while (t >= 0) {
			cin >> beauty >> num;
			//cout << beauty << num << endl;
			t--;
			if (t == 0 && flag == 0) {
				if (k < num)
					Re[i] = tBeauty + beauty*k;
				else 
					Re[i] = tBeauty + beauty*num;
				break;
			}
			if (k <= num && flag == 0) {
				Re[i] = tBeauty + beauty*k;
				flag = 1;
			}
			else if (flag == 1) {
				continue;
			}
			else {
				tBeauty += beauty*num;
				k = k - num;
			}
			
		}
		//cout << "end" << endl;
	}
	for (int i = 0; i < numP; i++)
		cout << Re[i] << endl;
}