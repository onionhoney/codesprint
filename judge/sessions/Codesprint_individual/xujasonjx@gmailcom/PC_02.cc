//
//  ProblemC.cpp
//  CodeSprint
//
//  Created by Jason Xu on 1/28/17.
//  Copyright © 2017 Jason Xu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

string problemC(int dims[], int startr, int startc, char ** map)
{
	string route = "";
	int r = startr-1, c = startc-1;
	int visited[dims[0]][dims[1]];
	for (int i = 0; i < dims[0]; i++)
		for (int j = 0; j < dims[1]; j++)
			visited[i][j] = 0;
	for (int s = 0; s < dims[0]*dims[1]; s++)
	{
		if (r > 0 && map[r-1][c] == '#' && visited[r-1][c] != 1)
		{
			route += 'U';
			visited[r-1][c] = 1;
			r -= 1;
		}
		else if (r < dims[0]-1 && map[r+1][c] == '#' && visited[r+1][c] != 1)
		{
			route += 'D';
			visited[r+1][c] = 1;
			r += 1;
		}
		else if (c > 0 && map[r][c-1] == '#' && visited[r][c-1] != 1)
		{
			route += 'L';
			visited[r][c-1] = 1;
			c -= 1;
		}
		else if (c < dims[1]-1 && map[r][c+1] == '#' && visited[r][c+1] != 1)
		{
			route += 'R';
			visited[r][c+1] = 1;
			c += 1;
		}
		else
			break;
	}
	return route;
}

int main()
{
	int num_t;
	int dims[2];
	int startr, startc;
	cin >> num_t;
	string route;
	
	for (int i = 0; i < num_t; i++)
	{
		cin >> dims[0] >> dims[1];
		cin >> startr >> startc;
		char ** map;
		map = new char * [dims[0]];
		for (int r = 0; r < dims[0]; r++)
			map[r] = new char[dims[1]];
		for (int r = 0; r < dims[0]; r++)
			for (int c = 0; c < dims[1]; c++)
				cin >> map[r][c];
		route = problemC(dims, startr, startc, map);
	}
	for (int i = 0; i < num_t; i++)
		cout << route << endl;
}