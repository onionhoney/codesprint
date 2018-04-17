#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <list>

using namespace std;

int main()
{
	int testCases;
	cin >> testCases;
	for (int k = 0; k < testCases; k++)
	{
		int row, col;
		cin >> row >> col;
		int a, b;
		cin >> a >> b; //whisker start position 1-based
		 //remove this
		char arr[100][100];

		for (int x = 0; x < row; x++)
		{
			string t;
			cin >> t;
			for (int y = 0; y < col; y++)
			{
				arr[x][y] = t[y];
			}
		}
		
		bool barr[100][100];

		for (int x = 0; x < row; x++)
		{
			for (int y = 0; y < col; y++)
			{
				barr[x][y] = false;
			}
		}
		string ans;
		//array initialized
		barr[a - 1][b - 1] = true;
		int x = a - 1;
		int y = b - 1;
		while (true)
		{
			//cout << "enter" << endl;
			//start at whisker position
			if (x > 0 && arr[x - 1][y] == '#' && !barr[x-1][y])
			{
				ans += "U";  //l
				barr[x - 1][y] = true;
				x--;
			}
			else if (x < row - 1 && arr[x + 1][y] == '#' && !barr[x + 1][y])
			{
				ans += "D"; //r
				barr[x + 1][y] = true;
				x++;
			}
			else if (y > 0 && arr[x][y - 1] == '#' && !barr[x][y - 1])
			{
				ans += "L"; //u
				barr[x][y - 1] = true;
				y--;
			}
			else if (y < col - 1 && arr[x][y + 1] == '#' && !barr[x][y + 1])
			{
				ans += "R"; //d
				barr[x][y + 1] = true;
				y++;
			}
			else
			{
				cout << ans << endl;
				break;
			}
		}
	}
}
