#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

int stringToInt(string s)
{
	int i = 1;
	int n = 0;
	for(char c = s.length() - 1; c >= 0; c--)
	{
		n += (c - '0') * i;
		i *= 10;
	}
}

void findNumbers(int * combo, int * lock)
{
	int highNum = 100;
	int lowNum = 1;
	int medNum = 50;
	int temp;

	for (int i = 0; i < 3; i++)
	{
		if (lock[medNum] == 2)
			combo[i] = medNum;
		else if (lock[medNum] == 0)
		{
			temp = medNum;
			medNum = (temp + highNum) / 2;
			lowNum = temp;
		}
		else if (lock[medNum] == 1)
		{
			temp = medNum;
			medNum = (temp + lowNum) / 2;
			highNum = temp;
		}
	}
}
int main(int argc, char* argv[])
{
	string line;
	ifstream myfile;
	myfile.open(argv[1]);
	string lines[10000];

	getline(myfile, line);
	int numTrials = stringToInt(line);

	for (int i = 0; i < numTrials; i++)
	{
		getline(myfile, line);
		stringstream stream(line);
		int lock[100];
		int num = 1;
		while (1) {
			int n;
			stream >> n;
			if (!stream)
			{
				lock[num] = n;
				num++;
				break;
			}
			
		}

		int combo[3];
		findNumbers(combo, lock);
		for (int i = 0; i < 3; i++)
			cout << combo[i];
		cout << endl;
	}
}