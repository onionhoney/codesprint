//
//  main.cpp
//  CodeSprint
//
//  Created by Jason Xu on 1/28/17.
//  Copyright © 2017 Jason Xu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int problemA(int num_type, int limit, int flows[][2])
{
	int beaut = 0;
	int found = 0;
	
	for (int i = 0; i < num_type; i++)
	{
		for (int j = 0; j < flows[i][1]; j++)
		{
			beaut += flows[i][0];
			found++;
			if (found >= limit)
				return beaut;
		}
	}
	return beaut;
}

int main()
{
	int num_t, num_types, limit;
	cin >> num_t;
	int ans[num_t];
	
	for (int i = 0; i < num_t; i++)
	{
		cin >> num_types >> limit;
		int flows[num_types][2];
		for (int j = 0; j < num_types; j++)
			cin >> flows[j][0] >> flows[j][1];
		ans[i] = problemA(num_types, limit, flows);
	}
	for (int i = 0; i < num_t; i++)
		cout << ans[i] << endl;
}
