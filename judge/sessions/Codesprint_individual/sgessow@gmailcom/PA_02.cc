#include<iostream>
//#include<string>

using namespace std;
int numTests = 0;//t

//int totalFlowers = 0;//n
//int totalFlowerTypes = 0;//p
int main()
{
	cin >> numTests;
	for (int i = 0; i < numTests; i++)
	{
		int score = 0;
		int numTypes = 0;//p
		int numFlowers = 0;//n
		cin >> numTypes >> numFlowers;
		int tempScore = 0;
		int tempNumFlowers = 0;
		bool first = true;
		for (int i = 0; i < numTypes; i++)
		{
			int type = 0;
			int numOfType = 0;
			cin >> type >> numOfType;
			if (tempNumFlowers+numOfType < numFlowers)
			{
				score += type*numOfType;
			}
			else if (tempNumFlowers + numOfType > numFlowers && first)
			{
				score += type*(numFlowers - tempNumFlowers);
				first = false;
			}
			tempNumFlowers += numOfType;
		}
		cout << score << endl;
	}
	//system("pause");
	return 0;
}