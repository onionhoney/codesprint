#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
	int testcase, flowerType, number;
	cin >> testcase;
	vector<int> res;
	for (int i = 0; i < testcase; i++) {
	  cin >> flowerType >> number;
	  int k = number;
	  int rest = 0;
	        for (int j = 0; j < flowerType; j++) {
			int beauty, maxDraw;
			cin >> beauty >> maxDraw;
			if(k >=0){
			  if(k >= maxDraw){
			    rest = rest + maxDraw*beauty;
			    k = k - maxDraw;
			    continue;
			  }
			  else{
			    rest = rest + k * beauty;
			    break;
			  }
			}
		}
		res.push_back(rest);
	}
	for(int i = 0; i< res.size();i++)
	  cout << res[i] << endl;
	return 0;
}



