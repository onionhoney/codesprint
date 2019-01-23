#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

  string line;
  
  int trials;
  cin >> trials;
  getline(cin, line);
  
  for (int k = 0; k < trials; k++) {
  
    int limit;
    cin >> limit;
    getline(cin, line);

    int cs31;
    int cs32;
    cin >> cs31 >> cs32;
    getline(cin, line);
  
    int arr31[cs31];
    int arr32[cs32];

    for (int i = 0; i < cs31; i++) {
      cin >> arr31[i];
    }
    for (int i = 0; i < cs32; i++) {
      cin >> arr32[i];
    }
  
    int maxStudents = 0;
    for (int i = 0; i < cs31; i++) {
      for (int j = 0; j < cs32; j++) {
	int sum = arr31[i] + arr32[j];
	if ((sum <= limit) && (sum > maxStudents)) {
	  maxStudents = sum;
	}
      }
    }

    cout << maxStudents << endl;

  }

  return 0;
}
