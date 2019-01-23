#include <iostream>
#include <vector>

using namespace std;



int main() {
	int test_cases;
	cin >> test_cases;
	for (int i = 0; i < test_cases; i++) {
		int jumps;
		cin >> jumps;
		int cs31_options;
		int cs32_options;
		cin >> cs31_options >> cs32_options;
		vector<int> cs31;
		vector<int> cs32;
		for (int j = 0; j < cs31_options; j++) {
			int students;
			cin >> students;
			cs31.push_back(students);
		}
		for (int j = 0; j < cs32_options; j++) {
			int students;
			cin >> students;
			cs32.push_back(students);
		}
		

		int max = 0;
		for (int j = 0; j < cs31.size(); j++) {
			for (int k = 0; k < cs32.size(); k++) {
				int sum = cs31[j] + cs32[k];
				if (max < sum && sum <= jumps)
					max = sum;
				
			}		
		}
		cout << max << "\n";
	}
}
