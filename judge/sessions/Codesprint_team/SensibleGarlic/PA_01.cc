#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    vector<char> distinct;
    for (int j = 0; j < s.length(); j++) {
      bool found = false;
      char x = s[j];
      if (x <= 'Z') {
        x -= 32;
      }
      for (int k = 0; k < distinct.size(); k++) {
        if (x == distinct[k]) {
          found = true;
          break;
        }
      }
      if (!found) {
        distinct.push_back(x);
      }
    }
    cout << (distinct.size()%2 == 0 ? "INVITE TO PARTY" : "TRASH TALK THE USER") << endl;
  }
}
