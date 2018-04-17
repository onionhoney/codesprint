#include <iostream>
#include <string>
#include <cctype>
using namespace std;
long a[1000000], b[1000000];
char chs[1000000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		cin.ignore(1);
		cin >> chs[i];
	}
	for (int i = 0; i < 4; i++)
	{
		int wh;
		cin >> wh;
		char chr = 'a';
		for (int j = 0; j < n; j++)
		{
			if (a[j] <= wh && b[j] >= wh) chr = chs[j];
		}
		cout << chr << " ";
	}
	cout << endl;
}