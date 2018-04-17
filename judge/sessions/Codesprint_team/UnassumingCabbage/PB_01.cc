//
//  TeamCabbageB.cpp
//  CodeSprint
//
//  Created by Jason Xu on 1/28/17.
//  Copyright © 2017 Jason Xu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

bool onMap(int dims[], int x, int y)
{
	if (x < 0 || x >= dims[0])
		return false;
	if (y < 0 || y >= dims[1])
		return false;
	return true;
}

int probB(int dims[], int num_mines, int mines[][2])
{
	int map[dims[0]][dims[1]];
	int candies = 0;
	for (int i = 0; i < dims[0]; i++)
		for (int j = 0; j < dims[1]; j++)
			map[i][j] = 0;
	int x = 0, y = 0;
	for (int i = 0; i < num_mines; i++)
	{
		x = mines[i][0]-1;
		y = mines[i][1]-1;
		if (onMap(dims, x-1, y-1) && map[x-1][y-1] != -1)
		{
			candies++;
			map[x-1][y-1]++;
		}
		if (onMap(dims, x, y-1) && map[x][y-1] != -1)
		{
			candies++;
			map[x][y-1]++;
		}
		if (onMap(dims, x-1, y) && map[x-1][y] != -1)
		{
			candies++;
			map[x-1][y]++;
		}
		if (onMap(dims, x, y+1) && map[x][y+1] != -1)
		{
			candies++;
			map[x][y+1]++;
		}
		if (onMap(dims, x+1, y) && map[x+1][y] != -1)
		{
			candies++;
			map[x+1][y]++;
		}
		if (onMap(dims, x+1, y+1) && map[x+1][y+1] != -1)
		{
			candies++;
			map[x+1][y+1]++;
		}
		if (onMap(dims, x-1, y+1) && map[x-1][y+1] != -1)
		{
			candies++;
			map[x-1][y+1]++;
		}
		if (onMap(dims, x+1, y-1) && map[x+1][y-1] != -1)
		{
			candies++;
			map[x+1][y-1]++;
		}
		candies -= map[x][y];
		map[x][y] = -1;
	}
	return candies;
}

int main()
{
	int num_t, num_mines;
	int dims[2];
	cin >> num_t;
	int ans[num_t];
	
	for (int i = 0; i < num_t; i++)
	{
		cin >> dims[0] >> dims[1];
		cin >> num_mines;
		int mines[num_mines][2];
		for (int j = 0; j < num_mines; j++)
			cin >> mines[j][0] >> mines[j][1];
		ans[i] = probB(dims, num_mines, mines);
	}
	for (int i = 0; i < num_t; i++)
		cout << ans[i] << endl;
}