#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

float getDist(float x1, float y1, float x2, float y2) {
	return sqrt(pow(x2 - x1, 2) +  pow(y2 - y1, 2));
}

bool isInside(int r, int a) {
	return (a * sqrt(2) <= r);
}

int getPoints(float c, int r) {
	int count = 0;

	for (int y = r; y >= 1; y--) {
		for (int x = (r * -1) - 1; x <= r + 1; x++) {
			if (getDist(c, 0, x, y) <= r) {
				count++;
			}
		}
	}
    count *= 2;

	count += r * 2;
    count++;
	if (c != 0) {
		count--;
	}

	return count;


}

int main() {
	int cas;
	cin >> cas;
	for (int canum = 0; canum < cas; canum++) {
		int r;
		cin >> r;
        if(r == 1){
            cout << 5<<endl;
            continue;
        }


		if (isInside(r, r - 1)) {
			cout << getPoints(0, r) << endl;
		}
		else {
			float edgeX = sqrt(pow(r, 2) - pow(r - 1, 2));
			float shift = (r - 1) - edgeX;
				cout << getPoints(shift, r) << endl;

		}

	}

}
