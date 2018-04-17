#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int maxBeauty(int number, map<int, int> flower, set<int> beauty);
int main() {
	int testcase, flowerType, number;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> flowerType;
		cin >> number;
		map<int, int> flower;
		set<int> beautyList;
		for (int j = 0; j < flowerType; j++) {
			int beauty, maxDraw;
			cin >> beauty;
			cin >> maxDraw;
			flower.insert(make_pair(beauty, maxDraw));
			beautyList.insert(beauty);
		}
		int maxB = maxBeauty(number, flower,beautyList);
		cout << maxB << endl;
	}
}

int maxBeauty(int number, map<int, int> flower, set<int> beauty) {
	int res = 0;
	set<int>::reverse_iterator rit = beauty.rbegin();
	int left = number;
	while(left){
	  int maxBeauty = *rit;
	  int maxBeautyNumber = flower[maxBeauty]; 
	  if(maxBeautyNumber <= left){
	    res = res + maxBeautyNumber*maxBeauty;
	    left = left - maxBeautyNumber;
	    beauty.erase(maxBeauty);
	    continue;
	  }
	  else{
	    res = res + maxBeauty * left;
	    left = 0;
	    continue;
	  }
	  }
	return res;
}


