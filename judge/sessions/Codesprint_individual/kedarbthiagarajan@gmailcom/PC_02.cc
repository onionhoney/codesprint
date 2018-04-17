//
//  main.cpp
//  codesprint
//
//  Created by Kedar Thiagarajan on 1/28/17.
//  Copyright © 2017 Kedar Thiagarajan. All rights reserved.
//

using namespace std;
#include <vector>
#include <iostream>
#include <string>
#include <math.h>

int main()
{
    int t;
    cin >> t;
    for(int i =0; i < t; i++)
    {
        bool possibleMoves = true;
        int m,n;
        cin >> m >> n;
        int a, b;
        cin >> a >> b;
        char grid[m][n];
        string row;
        for(int j = 0; j < m; j++)
        {
            cin >> row;
            for(int k = 0; k < row.size(); k++)
            {
                grid[j][k] = row[k];
            }
        }
        
        string whiskerString = "";
        int currentx = a;
        int currenty = b;
        for(int l = 0; l < m; l++)
            for( int p = 0; p < n; p++)
                if(grid[l][p] == 'S')
                {
                    currentx = l;
                    currenty = p;
                }
        
        while(possibleMoves)
        {
            if(currentx > 0 && grid[currentx - 1][currenty] == '#')
            {
                whiskerString += 'U';
                grid[currentx][currenty] = '.';
                currentx = currentx - 1;
                
            }
            else if(currentx < m  && grid[currentx + 1][currenty] == '#')
            {
                whiskerString += 'D';
                grid[currentx][currenty] = '.';
                currentx = currentx + 1;
            }
            else if(currenty < n  && grid[currentx][currenty + 1] == '#')
            {
                whiskerString += 'R';
                grid[currentx][currenty] = '.';
                currenty = currenty + 1;
            }
            else if(currenty > 0  && grid[currentx][currenty - 1] == '#')
            {
                whiskerString += 'L';
                grid[currentx][currenty] = '.';
                currenty = currenty - 1;
            }
            else
                possibleMoves = false;
        }
        
        cout << whiskerString << endl;
    }
}