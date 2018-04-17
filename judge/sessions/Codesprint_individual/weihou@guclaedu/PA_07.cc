#include<iostream>

using namespace std;

int main() {
	int numP;
	cin >> numP;
	int m, n;
	int Re[100];
	
	
	for (int i = 0; i < numP; i++) {
		cin >> m >> n;
		int num;
		cin >> num;
		//cout << num << endl;
		int x1, y1, x2, y2;
		int x = 1;
		int y = 1;
		for (int j = 0; j < num; j++) {
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 == x2 && x1!= 0 && x2 != 0 && y1 != m && y2 != m)
				x += 1;
			else if (y1 == y2 && y1 != 0 && y2 != 0 && y1 != n && y2 != n)
				y += 1;
		}
		Re[i] = x*y;
		//cout << "end" << endl;
	}
	for (int i = 0; i < numP; i++)
		cout << Re[i] << endl;
}