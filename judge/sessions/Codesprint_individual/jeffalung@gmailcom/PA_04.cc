#include <iostream>
#include <algorithm>
using namespace std;


int test(int numFlowerTypes, int numFlowersCanDraw, int* flowerBeauty, int *tirednessNum); 

int main()
{
	int numTests, numFlowerTypes[100], numFlowersCanDraw[100], testResults[100];
	cin >> numTests;

	for (int i = 0; i < numTests; i++)
	{
		cin >> numFlowerTypes[i] >> numFlowersCanDraw[i];
		int *flowerBeauty = new int[numFlowerTypes[i]];
		int *tirednessNum = new int[numFlowerTypes[i]];
		for (int j = 0; j < numFlowerTypes[i]; j++)
		{
			cin >> flowerBeauty[j] >> tirednessNum[j];
			//cerr << endl << flowerBeauty[j] << tirednessNum[j] << endl; // delete this later
		}
		testResults[i] = test(numFlowerTypes[i], numFlowersCanDraw[i], flowerBeauty, tirednessNum);
		delete[] flowerBeauty;
		delete[] tirednessNum;
	}

	//cout << endl;

	for (int i = 0; i < numTests; i++)
	{
		cout << testResults[i] << endl;
	}
	//cout << endl;
}

int test(int numFlowerTypes, int numFlowersCanDraw, int* flowerBeauty, int *tirednessNum)
{
	int maxBeauty = 0;
	//int *sortedFlowerBeauty = new int[numFlowerTypes];
	//int *sortedTirednessNum = new int[numFlowerTypes];
	int max;
	int pos = 0;
	for (int i = 0; i < numFlowerTypes; i++)
	{
		max = flowerBeauty[i];
		for (int j = i; j < numFlowerTypes; j++)
		{
			if (flowerBeauty[j] > max)
			{
				max = flowerBeauty[j];
				pos = j;
			}
		}
		//cerr << "MAX at " << i << ": "<< max << endl;
		if (max > flowerBeauty[i])
		{
			flowerBeauty[pos] = flowerBeauty[i];
			flowerBeauty[i] = max;
			int temp = tirednessNum[i];
			tirednessNum[i] = tirednessNum[pos];
			tirednessNum[pos] = temp;
		}
	}

	/*for (int i = 0; i < numFlowerTypes; i++) // delete this later
	{
		cerr << "flowerBeauty: " << flowerBeauty[i] << " " << "tirednessNum: " << tirednessNum[i] << endl;
	}*/
	int flowerNum = 0;
	int numThisFlower = 0;
	int maxFlowers = numFlowersCanDraw;
	int i = 0;
	while (i < maxFlowers)
	{
		maxBeauty += flowerBeauty[flowerNum];
		numThisFlower++;
		if (tirednessNum[flowerNum] == numThisFlower)
		{
			if (flowerNum == (numFlowerTypes - 1))
				break;
			else
			{
				flowerNum++;
				numThisFlower = 0;
			}
		}
		//cerr << "maxBeauty: " << maxBeauty << endl; // delete this later
		i++;
	}
	//delete [] sortedFlowerBeauty;
	//delete [] sortedTirednessNum;
	return maxBeauty;
}