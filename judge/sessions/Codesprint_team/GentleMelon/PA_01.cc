#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

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
		char letters[1000];
		for (int i=0;i<input.length();i++)
		{
			bool inLetters = false;
			char current = putchar(tolower(input[i]));
			for (char j : letters)
			{
				if (j == current)
				{
					inLetters = true;
				}
			}
			if (!inLetters)
			{
				letters[i] = current;
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