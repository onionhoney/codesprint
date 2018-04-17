#include <iostream>
#include <vector>

using namespace std;

int maxField(int flowerTypes, int flowerNum, vector<int>& beautys, vector<int>& beautyNums)
{
	int flowers = 0, beauty = 0, index = 0;
	while (flowers < flowerNum) {
		for (int i = 0; i < beautyNums[index]; i++) {
			if (flowers == flowerNum) break;
			beauty += (beautys[index]);
			flowers++;
		}
		index++;
	}
	cout << "Beauty: " << beauty << endl;
	return beauty;
}
int main()
{
	int n, flowerTypes, flowerNum;
	vector<int> beautys;
	vector<int> beautyNums;
	vector<int> output;
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
		output.push_back(maxField(flowerTypes, flowerNum, beautys, beautyNums));
	}
	return 0;
}