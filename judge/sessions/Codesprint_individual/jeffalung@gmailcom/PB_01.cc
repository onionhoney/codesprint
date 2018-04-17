#include<iostream>
using namespace std;

int test(int numLines, int *x, int *y, int *xtwo, int *ytwo);

int main()
{
	int numTests, length[100], width[100], numLines[100], testResults[100];
	cin >> numTests;

	for (int i = 0; i < numTests; i++)
	{
		cin >> length[i] >> width[i];
		cin >> numLines[i];
		int *x = new int[numLines[i]];
		int *y = new int[numLines[i]];
		int *xtwo = new int[numLines[i]];
		int *ytwo = new int[numLines[i]];
		for (int j = 0; j < numLines[i]; j++)
		{
			cin >> x[j] >> y[j] >> xtwo[j] >> ytwo[j];
			//cerr << endl << flowerBeauty[j] << tirednessNum[j] << endl; // delete this later
		}
		testResults[i] = test(numLines[i], x, y, xtwo, ytwo);
		delete[] x;
		delete[] y;
		delete[] xtwo;
		delete[] ytwo;
	}

	for (int i = 0; i < numTests; i++)
	{
		cout << testResults[i] << endl;
	}
}

int test(int numLines, int *x, int *y, int *xtwo, int *ytwo)
{
	int numTrueVertical = 0, numTrueHorizontal = 0;
	for (int i = 0; i < numLines; i++)
	{
		if (x[i] == xtwo[i])
			numTrueVertical++;
	}
	return ((numLines - numTrueVertical + 1)*(numTrueVertical + 1));
	// find numTrueVertical and numTrueHortizontal
	// return (numTrueVertical + 1) * (numTrueHorizontal + 1);
}

/*bool isVertical(int x, int y, int xx, int yy)
{
	return x == xx;
}*/

/*bool isHorizontal(int x, int y, int xx, int yy)
{
	return (y == yy);
}*/
/*
bool isRedundantLine(int x, int y, int xx, int yy, int xxx, int yyy, int xxxx, int yyyy)
{
	if (x == xxx && y == yyy && xx == xxxx && yy == yyyy)
		return true;
	else if ()
		return true;
	else
		return false;
}*/

// need to check that line is within bounds of grid?