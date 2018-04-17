#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int cases = 0;
	cin >> cases;
	for (int ca = 0; ca < cases; ca++) {
		int lengthRoad;
		int numLights;
		int speedLim;

		cin >> lengthRoad >> numLights >> speedLim;

		vector<int> locations;
		vector<int> periods;

		for (int i = 0; i < numLights; i++) {
			int tmp1, tmp2;

			cin >> tmp1 >> tmp2;
			locations.push_back(tmp1);
			periods.push_back(tmp2);


		}

		bool printedOut = false;
		for (int speed = speedLim; speed >= 0; speed--) {
			bool done = true;

			for (int i = 0; i < numLights; i++) {
				float time = (1.0 * locations[i]) / speed;
				int stage = time / periods[i];
				if (stage % 2 == 1) {
					done = false;
					break;
				}
			}

			if (done) {
				printedOut = true;
				cout << speed << endl;
				break;
			}


			
		}
		if (!printedOut) {
			cout << -1 << endl;

		}

	}




}