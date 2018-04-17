#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;

	bool* output = new bool[t];

	for (int i = 0; i < t; i++)
	{
		string username = "";
		cin >> username;

		int alphabet[26];
		for (int j = 0; j < 26; j++) {
			alphabet[j] = 0;
		}

		for (int j = 0, len = username.length(); j < len; j++) {
			char c = username[j];
			if (isalpha(c)) {
				int n = tolower(c) - 'a';
				alphabet[n]++;
			}
		}
		int count = 0;
		for (int j = 0; j < 26; j++) {
			if (alphabet[j] != 0) {
				count++;
			}
		}
		output[t] = (count % 2 == 0);
	}

	for (int i = 0; i < t; i++) {
		if (output[i])
			cout << "INVITE TO PARTY" << endl;
		else
			cout << "TRASH TALK THE USER" << endl;
	}
	
}