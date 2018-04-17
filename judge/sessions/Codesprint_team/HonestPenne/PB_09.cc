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
    
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> m >> n; // first line (y, x)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] = 0;
            }
        }
        
        cin >> k;
        while (k != 0) // take in all k coordinates and add mines
        {
            cin >> x >> y;
            board[y - 1][x - 1] = 1;
            k--;
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) // i = x
        {
            for (int j = 0; j < m; j++) // j = y
            {
                if (i - 1 >= 0 && board[j][i - 1] == 1)
                    count++;
                if (i + 1 < 1000 && board[j][i + 1] == 1)
                    count++;
                if (j - 1 >= 0 && board[j - 1][i] == 1)
                    count++;
                if (j + 1 < 1000 && board[j + 1][i] == 1)
                    count++;
            }
        }
        results[i] = count;
    }
    for (int i = 0; i < t; i++)
    {
        cout << results[i] + 1 << endl;
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
