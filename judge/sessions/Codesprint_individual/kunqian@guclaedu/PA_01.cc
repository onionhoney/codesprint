#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Flower {
public:
	Flower(int beauty, int max);
	int beauty;
	int max;
};

Flower::Flower(int beauty, int max) {
	this->beauty = beauty;
	this->max = max;
}

bool sort_func(Flower* i, Flower* j) {
	return i->beauty > j->beauty;
}

int main(int argc, char *argv[]) {
	int test_case_amt;
	cin >> test_case_amt;
	vector<int> results;
	
	for (int k = 0; k < test_case_amt; k++) {
		int types_of_flowers, max_draw_flowers;
		cin >> types_of_flowers;
		cin >> max_draw_flowers;
		
		vector<Flower*> the_flowers;
		int temp_beauty, temp_max;
		for (int i = 0; i < types_of_flowers; i++) {
			cin >> temp_beauty;
			cin >> temp_max;
			the_flowers.push_back(new Flower(temp_beauty, temp_max));
		}
		
		sort(the_flowers.begin(), the_flowers.end(), sort_func);
		
		int count = max_draw_flowers;
		int total_beauty = 0;
		for (int j = 0; j < the_flowers.size(); j++) {
//			cout << "flower data: " << the_flowers[j]->beauty << " " << the_flowers[j]->max << "\n";
			while (the_flowers[j]->max > 0) {
				total_beauty += the_flowers[j]->beauty;
				the_flowers[j]->max = the_flowers[j]->max-1;
				count--;
				if (count <= 0) {
					
					break;
				}
			}
		}
		
		results.push_back(total_beauty);
	}
	
	for (int m = 0; m < results.size(); m++) {
		cout << results[m] << "\n";
	}	
}