//
//  main.cpp
//  CodeSprintGroupB
//
//  Created by Neel Manthani on 1/28/17.
//  Copyright © 2017 Neel Manthani. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int testCases;
    int rows, cols, bottles;
    int candy = 0;
    int x,y;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        cin >> rows;
        cin >> cols;
        int board[rows][cols];
        cin >> bottles;
        for (int i = 0; i < bottles; i++)
        {
            cin >> x;
            cin >> y;
            board[x-1][y-1] = 1;
        }
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] != 1)
                {
                    if (i > 0)
                    {
                        if (board[i-1][j] == 1)
                            candy++;
                    }
                    
                    if (j > 0)
                    {
                        if (board[i][j-1] == 1)
                            candy++;
                    }
                    
                    if (i < rows - 1)
                    {
                        if (board[i+1][j] == 1)
                            candy++;
                    }
                    
                    if (j < cols - 1)
                    {
                        if (board[i][j+1] == 1)
                            candy++;
                    }
                    
                    if (i > 0 && j > 0)
                    {
                        if (board[i-1][j-1] == 1)
                            candy++;
                    }
                    
                    if (i > 0 && j < cols-1)
                    {
                        if (board[i-1][j+1] == 1)
                            candy++;
                    }
                    
                    if (i < rows-1 && j > 0)
                    {
                        if (board[i+1][j-1] == 1)
                            candy++;
                    }
                    
                    if (i < rows-1 && j < cols-1)
                    {
                        if (board[i+1][j+1] == 1)
                            candy++;
                    }
                    
                }
            }
        }
        cout << candy << endl;
        candy = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                board[i][j] = 0;
    }
}
