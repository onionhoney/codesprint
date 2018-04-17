//
//  ProblemB.cpp
//  CodeSprint
//
//  Created by Jason Xu on 1/28/17.
//  Copyright © 2017 Jason Xu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int problemB(int dims[], int num_lines, int lines[][4])
{
	int h = 0, v = 0;
	for (int i = 0; i < num_lines; i++)
	{
		if (lines[i][0] == lines[i][2])
			h++;
		else
			v++;
	}
	return (h+1)*(v+1);
}

int main()
{
	int num_t, num_lines;
	int dims[2];
	cin >> num_t;
	int ans[num_t];
	
	for (int i = 0; i < num_t; i++)
	{
		cin >> dims[0] >> dims[1];
		cin >> num_lines;
		int lines[num_lines][4];
		for (int j = 0; j < num_lines; j++)
			cin >> lines[j][0] >> lines[j][1] >> lines[j][2] >> lines[j][3];
		ans[i] = problemB(dims, num_lines, lines);
	}
	for (int i = 0; i < num_t; i++)
		cout << ans[i] << endl;
}