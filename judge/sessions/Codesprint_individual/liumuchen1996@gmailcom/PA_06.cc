#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int maxBeauty(int number, map<int, int> flower, multiset<int> beauty);
int main() {
	int testcase, flowerType, number;
	cin >> testcase;
	vector<int> res;
	for (int i = 0; i < testcase; i++) {
	  cin >> flowerType >> number;
		map<int, int> flower;
		multiset<int> beautyList;
	        for (int j = 0; j < flowerType; j++) {
			int beauty, maxDraw;
			cin >> beauty >> maxDraw;		
			flower.insert(make_pair(beauty, maxDraw));
			beautyList.insert(beauty);
		}
		int maxB = maxBeauty(number, flower,beautyList);
		res.push_back(maxB);
	}
	for(int i = 0; i< res.size();i++)
	  cout << res[i] << endl;
}

int maxBeauty(int number, map<int, int> flower, multiset<int> beauty) {
	int res = 0;
	int size = beauty.size();
	multiset<int>::reverse_iterator rit = beauty.rbegin();
	int left = number;
	while(left && size > 0){
	  int maxBeauty = *rit;
	  int maxBeautyNumber = flower[maxBeauty]; 
	  if(maxBeautyNumber <= left){
	    res = res + maxBeautyNumber*maxBeauty;
	    left = left - maxBeautyNumber;
	    beauty.erase(maxBeauty);
	    size--;
	    continue;
	  }
	  else{
	    res = res + maxBeauty * left;
	    size --;
	    left = 0;
	    continue;
	  }
	  }
	return res;
}


