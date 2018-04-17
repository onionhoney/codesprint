#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>

using namespace std;

int main()
{
	int testCases;
	cin >> testCases;
	char arr[1000000];
	for (int x = 0; x < 1000000; x++)
	{
		arr[x] = 'a';
	}
	for (int x = 0; x < testCases; x++)
	{
		int l, r;
		cin >> l >> r;
		char ch;
		cin >> ch;
		for (int y = l; y <= r; y++)
			arr[y] = ch;
	}
	int a1, a2, a3, a4;
	cin >> a1 >> a2 >> a3 >> a4;
	cout << arr[a1] << " " << arr[a2] << " " << arr[a3] << " " << arr[a4] << " " << endl;
}
