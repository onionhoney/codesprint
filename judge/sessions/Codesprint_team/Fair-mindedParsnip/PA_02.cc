#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <stdlib.h>
#include <cassert>
#include <algorithm>
using namespace std;

int main() {
	int t(0);
	cin >> t;

	cin.ignore(INT_MAX, '\n');

	for (int j = t; j > 0; j--)
	{
		string u;
		int arr[26] = {};
		int count = 0;
		getline(cin, u);
		
		for (int i = 0; i < u.length(); i++)
		{
			if (isdigit(u[i]))
				continue;


		char test = tolower(u[i]);

			if (arr[test - 97] == 0)
			{

			arr[test - 97] = 1;
				count++;
			}

		else
				continue;
		}


	if (count % 2 == 0)
			cout << "INVITE TO PARTY\n";
		else
			cout << "TRASH TALK THE USER\n";

}
	return 0;
}