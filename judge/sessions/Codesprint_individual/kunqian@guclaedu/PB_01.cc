#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Point {
public:
	Point(int x, int y);
	int x;
	int y;
};
Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}


int main(int argc, char *argv[]) {
	int test_cases;
	cin >> test_cases;
	
	vector<int> results;
	
	for (int k = 0; k < test_cases; k++) {
		int land_x, land_y;
		cin >> land_x;
		cin >> land_y;
		
		int lines;
		cin >> lines;
		
		int horizontal_cut = 0, vertical_cut = 0;
		
		for (int i = 0; i < lines; i++) {
			int temp_x, temp_y;
			cin >> temp_x;
			cin >> temp_y;
			Point sp(temp_x, temp_y);
			
			cin >> temp_x;
			cin >> temp_y;
			Point ep(temp_x, temp_y);
			
			if (sp.x == 0) {
				if (sp.y != 0)
					horizontal_cut++;
			} else if (sp.y == 0) {
				vertical_cut++;
			}
		}
		
		results.push_back((horizontal_cut+1) * (vertical_cut+1));
	}
	
	for (int m = 0; m < results.size(); m++) {
		cout << results[m] << "\n";
	}
}