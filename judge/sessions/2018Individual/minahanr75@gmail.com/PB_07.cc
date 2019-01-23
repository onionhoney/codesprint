#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

int findNumbers(int * combo, int * lock)
{
        int highNum = 100;
        int lowNum = 1;
        int medNum = 50;
        int temp;
        while (lock[medNum] != 1)
        {
 /*           cout << "highNum is " << highNum << endl;
            cout << "medNum is " << medNum << endl;
            cout << "lowNum is " << lowNum << endl;*/
            if (lock[medNum] == 0)
            {
                temp = medNum;
                medNum = (temp + highNum) / 2;
                lowNum = temp;
            }
            else if (lock[medNum] == 2)
            {
                temp = medNum;
                medNum = (temp + lowNum) / 2;
                highNum = temp;
            }
        }
		return medNum;
}

int main(/*int argc, char* argv[]*/)
{
	string line;
	//ifstream myfile;
	//myfile.open("p2.txt");
	string lines[10000];

	getline(cin, line);
	int numTrials;
	stringstream stream(line);

	stream >> numTrials;
	for (int i = 0; i < numTrials; i++)
	{
		int combo[3];

		for (int j = 0; j < 3; j++)
		{
			getline(cin, line);
			stringstream stream(line);
			int lock[101];
			int num = 1;

			int n;
			while (stream >> n)
			{
				lock[num] = n;
				num++;
			}
			combo[j] = findNumbers(combo, lock);
		}

		for (int j = 0; j < 3; j++)
		{
			cout << combo[j];
			cout << " ";
		}
		cout << endl;
	}
}