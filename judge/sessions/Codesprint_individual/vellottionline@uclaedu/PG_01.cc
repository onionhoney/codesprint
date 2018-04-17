#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    vector<pair<string, int> > cur;
    int numVowels = 0;
    for (int k = 0; k < s.length(); k++) {
      bool found = false;
      for (int l = 0; l < cur.size(); l++) {
        pair<string,int> curStr = cur[l];
        if (curStr.first[0] == s[k]) {
          found = true;
          break;
        }
      }
      if (!found) {
        string m = string(1,s[k]);
        cur.push_back(make_pair(m, k));
        char x = s[k];
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
          numVowels++;
        }
      }
    }
cout << cur.size() << " " << numVowels << endl;
    for (int k = 2; k < s.length(); k++) {
      if (k > (s.length() + 1)/2) {
        cout << "0 0" << endl;
      } else {
        int num = 0;
        vector<pair<string, int> > newPairs;
        for (int l = 0; l < cur.size(); l++) {
          pair<string, int> curPair = cur[l];
          for (int m = 0; m < s.length(); m++) {
            if (m - curPair.second > 1) {
              bool found = false;
              for (int o = 0; o < newPairs.size(); o++) {
                pair<string,int> current = newPairs[o];
                if (current.first == (curPair.first + s[m])) {
                  found = true;
                  break;
                }
              }
              if (!found) {
                newPairs.push_back(make_pair(curPair.first + s[m], m));
                char x = s[m];
                if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
                  num++;
                }
              }
            }
          }
        }
        cout << newPairs.size() << " " << num << endl;
        cur = newPairs;
      }
    }
  }
}
