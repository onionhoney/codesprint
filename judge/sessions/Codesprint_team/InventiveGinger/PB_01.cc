#include <cmath>
#include <iostream>
using namespace std;
int getMines(int, int, int);
bool closeEnough(int,int,int,int);
int main(int argc, char const *argv[]) {
	int t = 0;
	cin >> t;
	int mrows = 0;
	int ncols = 0;
	int k = 0;
	for(int i = 0; i < t; i++){
		cin >> mrows >> ncols;
		cin >> k;
		cout << getMines(k, mrows, ncols) << endl;;
	}
	return 0;
}

int getMines(int k, int mrows, int ncols){
	int grid[k][2];
	int score = 0;
	for(int i = 0; i < k; i++){
		int x,y;
		cin >> x >> y;
		grid[i][0] = x;
		grid[i][1] = y;
		if (x == mrows || x == 1) {
			if( y == 1 || y == ncols){
				score += 3;
			} else {
				score += 5;
			}
			continue;
		}

		if(y == 1 || y == ncols){
			if(x == 1 || x == mrows){
				score += 3;
			} else {
				score += 5;
			}
			continue;
		}
	}
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			if(j != i){
				if(closeEnough(grid[i][0], grid[i][1], grid[j][0], grid[j][1])){
					score--;
				}
			}
		}
	}
	return score;
}

bool closeEnough(int x1, int y1, int x2, int y2){
	int distance = 0;
	distance = sqrt(pow(abs(x1-x2),2) + pow(abs(y1-y2),2));
	if(distance <= sqrt(2)){
		return true;
	}
	return false;
}
