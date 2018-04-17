#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	string s;
	cin >> t;
	cin.ignore(255, '\n');
	for (int i = 0; i < t; i++)
	{
		getline(cin, s);
		char arr[26];
		for (int m = 0; m < 26; m++)
			arr[m] = 0;
		for (int j = 0; j < s.size(); j++)
		{
			char c = tolower(s[j]);
			if (c >= 'a' && c <= 'z')
			{
				int k = c - 'a';
				arr[k] = 1;
			}
		}
		int sum = 0;
		for (int m = 0; m < 26; m++)
			sum += arr[m];
		if (sum % 2 == 0)
			cout << "INVITE TO PARTY" << endl;
		else
			cout << "TRASH TALK THE USER" << endl;
	}
}