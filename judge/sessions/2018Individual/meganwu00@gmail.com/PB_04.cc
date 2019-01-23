#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

  string line;
  ifstream myfile;
  myfile.open(argv[1]);
  
  int n;
  myfile >> n;
  getline(myfile, line);
  
  for (int i = 0; (i < n) && (myfile); i++) {
    for (int k = 0; k < 3; k++) {
      getline(myfile, line);
      int sum = 0;
      for (int j = 0; (j < line.length()) && (line[j] != 1); j++) {
	if (line[j] == '0') {
	  sum++;
	}
      }
      cout << sum;
      if (k != 2)
	cout << " ";
    }
    cout << endl;
  }

  return 0;
}
