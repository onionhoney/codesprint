#include <iostream>

using namespace std;
int wicked(int width, int height);
int isVert(int x1, int y1, int x2, int y2);

int main(){

	int t = 0;
	cin >> t;
	int width = 0;
	int height = 0;
	for(int i = 0; i < t; i++){
		cin >> width >> height;
		cout << wicked(width, height) << endl;
	}
}


int wicked(int width, int height){
	int k = 0;
	cin >> k;
	int districs = 1;
	int x1, x2, y1, y2;
	int horizonals = 1;
	int verticals = 1;
	for(int i = 0; i < k; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		if(isVert(x1, y1, x2, y2)){
			verticals++;
		} else {
			horizonals++;
		}
	}
	return horizonals * verticals;
}

int isVert(int x1, int y1, int x2, int y2){
	if ( x1 == x2 ) {
		return 1;
	}
	return 0;
}
