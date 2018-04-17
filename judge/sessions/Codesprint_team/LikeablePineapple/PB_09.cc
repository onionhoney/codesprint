//
//  main.cpp
//  teamB
//
//  Created by Lexie Kemp on 1/28/17.
//  Copyright © 2017 Lexie Kemp. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    cin.ignore(1000,'\n');
    int output[100];
    for (int a=0; a<t; a++)
    {
        int total=0;
        int m, n;
        cin>>m>>n;
        int board[1000][1000];
        int k;
        cin>>k;
        for (int r=0;r<m;r++)
        {
            for (int c=0;c<n;c++)
            {
                board[r][c]=0;
            }
        }
        for (int i=0;i<k;i++)
        {
            int x,y;
            cin>>x>>y;
            board[x-1][y-1]=-1;
        }
        for (int r=0;r<m;r++)
        {
            for (int c=0;c<n;c++)
            {
                int count=0;
                if (board[r][c]==0)
                {
                    if (c>0&&board[r][c-1]==-1)
                        count++;
                    if (c<n-1&&board[r][c+1]==-1)
                        count++;
                    if (r>0&&board[r-1][c]==-1)
                        count++;
                    if (r<m-1&&board[r+1][c]==-1)
                        count++;
                    if (r>0&&c<n-1&&board[r-1][c+1]==-1)
                        count++;
                    if (c>0&&r>0&board[r-1][c-1]==-1)
                        count++;
                    if (c>0&&r<m-1&&board[r+1][c-1]==-1)
                        count++;
                    if (c<n-1&&r<m-1&&board[r+1][c+1]==-1)
                        count++;
                }
                total+=count;
            }
        }
        output[a]=total;
    }
    for (int d=0;d<t;d++)
    {
        cout<<output[d]<<endl;
    }
}
