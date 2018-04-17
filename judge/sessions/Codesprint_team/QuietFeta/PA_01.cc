#include<iostream>
#include <string>
#include<algorithm>
using namespace std;

int main() {
	int num = 0;
	cin >> num;
	int all[26];
	
	bool Re[100];
	string name;
	for (int i = 0; i < num; i++) {
		for (int i = 0; i < 26; i++) {
			all[i] = 0;
		}
		cin >> name;
		//cout << "end" << endl;
		int t = name.length();
		for (int j = 0; j < t; j++) {
			int in = name[j] - 'a';

			if (in < 0) {
				if (in <= -7 && in >= -32)
				{
					in += 32;
				}
			
				else
				{
					continue;
				}
			}
			all[in] = 1;
		}
		int total = 0;
		for (int k = 0; k < 26; k++) {
			total += all[k];
		}
		if (total % 2 == 0) {
			Re[i] = true;
		}
		else {
			Re[i] = false;
		}
		
	}
	for (int i = 0; i < num; i++) {
		if (Re[i]) {
			cout << "INVITE TO PARTY" << endl;
		}
		else {
			cout << "TRASH TALK THE USER" << endl;
		}
	}
}