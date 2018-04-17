
//  1 <= 50000 flowers
//  limit on each type of flower
// p is types of flowers
// n is number of flowers


#include <iostream>
#include <vector>

using namespace std;
int getTotalBeauty(int p, int n);

int main(int argc, char const *argv[]) {
	int t = 0;
	cin >> t;
	static int n;
	static int p;
	// the next p lines will describe the flowers rin can draw
	// p is total types of flowers
	for(int i = 0; i < t; i++){
		cin >> p >> n;
		cout << getTotalBeauty(p,n) << endl;
	}
	return 0;
}

int getTotalBeauty(int p, int n){
	int beautyFactor = 0;
	int numberWillingToDraw = 0;
	int totalBeauty = 0;
	int totalFlowersDrawn = 0;
	for (int i = 0; i < p; i++) {
		cin >> beautyFactor >> numberWillingToDraw;
		if ( totalFlowersDrawn < n) {
			int eachFlower = numberWillingToDraw + totalFlowersDrawn < n ? numberWillingToDraw : n - totalFlowersDrawn;
			totalFlowersDrawn += eachFlower;
			totalBeauty += beautyFactor * eachFlower;
		}
	}
	return totalBeauty;
}
