#include <iostream>
using namespace std;

int main() {
	int t, m, n;
	cin >> t;
	cin >> m;
	cin >> n;
	
	int* total = new int[t];

	for (int i = 0; i < t; i++)
	{
		int k;
		cin >> k;
		int horizontal = 0, vertical = 0;
		for (int j = 0; j < k; j++) {
			int xi, yi, xii, yii;
			cin >> xi;
			cin >> yi;
			cin >> xii;
			cin >> yii;

			if (xi == xii)
				vertical++;
			if (yi == yii)
				horizontal++;
		}

		total[i] = (horizontal + 1)* (vertical + 1);
	}

	for (int i = 0 ; i < t; i++)
		cout << total[i] << endl;

}