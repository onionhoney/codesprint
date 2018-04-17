/* @file team.cpp
NOTES
Print a '\n' after every answer to cout
*/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;
void B();

int main()
{
	B();
}

void B()
{
	int t = 0;
	int m;
	int n;
	int k;
	int x;
	int y;
	int results[100];
	int	board[1000][1000];

	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			board[i][j] = 0;
		}
	}

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int mineNum = 0;
		cin >> m >> n; // first line
		cin >> k;
		while (k != 0) // take in all k coordinates and add mines
		{
			cin >> x >> y;
			board[y - 1][x - 1]++;
		}
		int count = 0;
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 1000; j++)
			{
				if (x - 1 > 0)
					count += board[y][x - 1];
				if (x + 1 < 1000)
					count += board[y][x + 1];
				if (y - 1 > 0)
					count += board[y][x - 1];
				if (y + 1 < 1000)
					count += board[y][x + 1];
			}
		}
		results[i] = count;
	}
	for (int i = 0; i < t; i++)
	{
		cout << results[i] << endl;
	}
}

/*if (x - 1 > 0)
board[y][x - 1]++;
if (x + 1 < 1000)
board[y][x + 1]++;
if (y - 1 > 0)
board[y][x - 1]++;
if (y + 1 < 1000)
board[y][x + 1]++;*/