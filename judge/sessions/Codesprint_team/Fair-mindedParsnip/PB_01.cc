#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

using namespace std;

//always include endl with cout <<

int rows, cols;
int tubes;
int candy;

int trows[10000];
int tcols[10000];

int candies(int row, int col, int tubes2);

int main()
{
	int testCases;
	cin >> testCases;

	for (int i = 0; i < testCases; i++)
	{
		cin >> rows >> cols;
		cin >> tubes;
		candy = 0;

		for (int j = 0; j < tubes; j++)
		{
			cin >> trows[j] >> tcols[j];
		}

		for (int j = 0; j < tubes; j++)
		{
			candy += candies(trows[j], tcols[j], j);
		}
		cout << candy << endl;
	}
	return 0;
}

int candies(int row, int col, int tubeNumber)
{
	int num = 0;
	for (int i = 0; i < tubes; i++)
	{
		if (i != tubeNumber)
		{
			row--;
			if (row >= 1 && row <= rows && col >= 1 && col <= cols && (row != trows[i] || col != tcols[i]))
			{
				//cout << "row: " << row << "col: " << col << endl;
				num++;
			}
			row++;

			row++;
			if (row >= 1 && row <= rows && col >= 1 && col <= cols && (row != trows[i] || col != tcols[i]))
			{
				//cout << "row: " << row << "col: " << col << endl;
				num++;
			}
			row--;

			col--;
			if (row >= 1 && row <= rows && col >= 1 && col <= cols && (row != trows[i] || col != tcols[i]))
			{
				//cout << "row: " << row << "col: " << col << endl;
				num++;
			}
			col++;

			col++;
			if (row >= 1 && row <= rows && col >= 1 && col <= cols && (row != trows[i] || col != tcols[i]))
			{
				//cout << "row: " << row << "col: " << col << endl;
				num++;
			}
			col--;

			row--;
			col--;
			if (row >= 1 && row <= rows && col >= 1 && col <= cols && (row != trows[i] || col != tcols[i]))
			{
				//cout << "row: " << row << "col: " << col << endl;
				num++;
			}
			row++;
			col++;

			row--;
			col++;
			if (row >= 1 && row <= rows && col >= 1 && col <= cols && (row != trows[i] || col != tcols[i]))
			{
				//cout << "row: " << row << "col: " << col << endl;
				num++;
			}
			row++;
			col--;

			row++;
			col++;
			if (row >= 1 && row <= rows && col >= 1 && col <= cols && (row != trows[i] || col != tcols[i]))
			{
				//cout << "row: " << row << "col: " << col << endl;
				num++;
			}
			row--;
			col--;

			row++;
			col--;
			if (row >= 1 && row <= rows && col >= 1 && col <= cols && (row != trows[i] || col != tcols[i]))
			{
				//cout << "row: " << row << "col: " << col << endl;
				num++;
			}
			row--;
			col++;
		}
	}
	return num;
}