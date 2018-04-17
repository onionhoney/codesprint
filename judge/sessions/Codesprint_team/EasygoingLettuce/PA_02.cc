#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
	int cases;
	cin >> cases;
	cin.ignore(10000, '\n');
	for (int cas = 0; cas < cases; cas++) {
		int ltr[26];
		for (int x = 0; x < 26; x++)
		{
			ltr[x] = 0;
		}
		string name;
		getline(cin, name);
		for (int i = 0; i < name.size(); i++) {
			if (isalpha(name[i]))
			{
				ltr[tolower(name[i]) - 'a']++;
			}
		}
		int distinct = 0;
		for (int x = 0; x < 26; x++)
		{
			if (ltr[x] > 0) distinct++;
		}
		if (distinct % 2 != 0)
		{
			cout << "TRASH TALK THE USER" << endl;
		}
		else
		{
			cout << "INVITE TO PARTY" << endl;
		}
	}
}