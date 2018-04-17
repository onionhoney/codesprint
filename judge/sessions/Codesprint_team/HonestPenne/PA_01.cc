#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	string array[100];
	int unique = 0;
	string id;
	string temp;

	int numID = 0;
	cin >> numID;

	for (int c = 0; c < numID; c++)
	{
		cin >> id;
		array[c] = id;
	}
	for (int c = 0; c < numID; c++)
	{
		temp = array[c];
		for (int i = 0; i < temp.size(); i++)
		{
			if (isalpha(temp[i]) && (islower(temp[i])))
			{
				temp[i] = toupper(temp[i]);
			}
		}
	}
	for (int c = 0; c < numID; c++)
	{
		for (int i = 'A'; i <= 'Z'; i++)
		{
			for (int n = 0; n < temp.size(); n++)
			{
				char hold = temp[n];
				if (hold == i)
				{
					unique++;
					break;
				}
			}
		}
		if ((unique % 2) == 0)
			array[c] = "yes";
		else
			array[c] = "no";
	}

	for (int c = 0; c < numID; c++)
	{
		if (array[c] == "yes")
			cout << "INVITE TO PARTY";
		else
			cout << "TRASH TALK THE USER";
	}
}