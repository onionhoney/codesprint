#include <iostream>
#include <string>
//#include <stdio.h>
//#include <ctype.h>
#include <vector>

using namespace std;
int cases = 0;
int main()
{
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		int count = 0;
		string input;
		cin >> input;
		
		for (int i=0;i<input.length();i++)
		{
			vector <char> letters;
			bool inLetters = false;
			char current = tolower(input[i]);
			for (char j:letters)
			{
				if (j == current)
				{
					inLetters = true;
				}
			}
			if (!inLetters)
			{
				letters.push_back(current);
				count++;
			}
		}
		
		if (count % 2 == 0)
		{
			cout << "INVITE TO PARTY" << endl;
		}
		else
		{
			cout << "TRASH TALK THE USER" << endl;
		}
		system("pause");
	}
	return 0;
}