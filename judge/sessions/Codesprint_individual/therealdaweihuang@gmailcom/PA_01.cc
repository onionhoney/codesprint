#include <iostream>
using namespace std;

int main() {
	int t, p, n;
	cin >> t;
	
	int* total = new int[t];

	for (int i = 0; i < t; i++)
	{
		cin >> p;
		cin >> n;

		for (int j = 0; j < p; j++) {

			int bi, ni;
			cin >> bi;
			cin >> ni;

			if (ni > n)
				ni = n;
			total[i] += bi*ni;
			n -= ni;
		}
	}

	for (int i = 0 ; i < t; i++)
		cout << total[i] << endl;

}