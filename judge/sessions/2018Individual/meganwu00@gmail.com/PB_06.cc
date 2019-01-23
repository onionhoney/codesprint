#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

  string line;
  // ifstream myfile;
    
  int n;
  cin >> n;
  getline(cin, line);
  
  string output;

  for (int i = 0; i < n; i++) {
    for (int k = 0; (k < 3) && getline(cin, line); k++) {
      int sum = 0;
      for (int j = 0; (j < line.length()) && (line[j] != 1); j++) {
	if (line[j] == '0') {
	  sum++;
	}
      }
      
      ostringstream oss;
      oss << sum;
      output.append(oss.str());
      if (k != 2) {
	output.append(" ");
      }
    }
    output.append("\n");
  }

  cout << output;
  
  return 0;
}
