#include <iostream>
#include <vector>

using namespace std;

int maxField(int flowerTypes, int flowerNum, vector<int>& beautys, vector<int>& beautyNums)
{
	int flowers = 0, beauty = 0, index = 0;
	while (flowers < flowerNum && index < flowerTypes) {
		for (int i = 0; i < beautyNums[index]; i++) {
			if (flowers == flowerNum) break;
			beauty += (beautys[index]);
			flowers++;
		}
		index++;
	}
	return beauty;
}
int main()
{
	int n, flowerTypes, flowerNum;
	vector<int> beautys;
	vector<int> beautyNums;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> flowerTypes;
		cin >> flowerNum;
		for (int j = 0; j < flowerTypes; j++) {
			int beauty, beautyNum;
			cin >> beauty;
			beautys.push_back(beauty);
			cin >> beautyNum;
			beautyNums.push_back(beautyNum);
		}
		cout << maxField(flowerTypes, flowerNum, beautys, beautyNums) << endl;
		beautys = {};
		beautyNums = {};
	}
	
	return 0;
}