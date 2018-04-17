#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	string answer[100];
	for (int i = 0; i != t; i++)
	{
		answer[i] = "";
		int m, n;
		cin >> m >> n;
		int a, b;
		cin >> a >> b;
		string map[100];
		getline(cin, map[0]);
		//cin.ignore(10000, '/n');
		for (int j = 0; j != m; j++)
			getline(cin, map[j]);
		while (100)
		{
			int j = 0;
			if (a != m && map[a][b - 1] == '#')
			{
				map[a][b] = '.';
				answer[i][j] = 'R';
				j++;
				a = a + 1;
			}
			else if (b != n && map[a - 1][b] == '#')
			{
				map[a][b] = '.';
				answer[i][j] = 'D';
				j++;
				b = b + 1;
			}
			else if (a != 1 && map[a - 2][b - 1] == '#')
			{
				map[a][b] = '.';
				answer[i][j] = 'U';
				j++;
				a = a - 1;
			}
			else if (b != 1 && map[a - 1][b - 2] == '#')
			{
				map[a][b] = '.';
				answer[i][j] = 'D';
				j++;
				b = b - 1;
			}
			else
				break;
		}
		

		
		
	}
	for (int bub = 0; bub != t; bub++)
		cout << answer[bub] << endl;
}