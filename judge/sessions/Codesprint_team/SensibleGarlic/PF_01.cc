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

int solve(vector<vector<int> > stuff, int dest) {
  vector<int> realDest = stuff[dest];
  int numOthers = 0;
  for (int i = 0; i < 3; i++) {
    if (i == dest) continue;
    numOthers += stuff[i].size();
  }
  if (numOthers == 0) return 0;
  int nextNeeded = numOthers + stuff[dest].size() - 1;
  int k;
  for (k = stuff[dest].size() - 1; k >= 0; k--) {
    if (stuff[dest][k] == nextNeeded) {
      nextNeeded--;
    } else {
      break;
    }
  }
  int other;
  for (int i = 0; i < 3; i++) {
    if (stuff[i][stuff[i].size() - 1] == nextNeeded) {
      break;
    }
  }
  vector<vector<int> > copy = vector<vector<int> >(3, vector<int>());
 for (int i = 0; i < 3; i++) {
    if (i == dest) {
      for (int l = 0; l <= k; l++) {
        copy[i].push_back(stuff[i][l]);
      }
    } else if (i == other) {
      for (int l = 0; l < stuff[i].size() - 1; l++) {
        copy[i].push_back(stuff[i][l]);
      }
    } else {
      for (int l = 0; l < stuff[i].size(); l++) {
        copy[i].push_back(stuff[i][l]);
      }
    }
  }
  int left = 0;
  if (left == other || left == dest) left++;
  if (left == other || left == dest) left++;
  return solve(copy, left) + pow(2, numOthers + stuff[dest].size());
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    vector<vector<int> > stuff(3, vector<int>());
    int n;
    cin >> n;
    int dest;
    for (int k = 0; k < n; k++) {
      int r;
      cin >> r;
      stuff[r-1].push_back(k);
      if (k == (n - 1)) {
        dest = r - 1;
      }
    }
    sort(stuff[0].begin(), stuff[0].end());
    sort(stuff[1].begin(), stuff[1].end());
    sort(stuff[2].begin(), stuff[2].end());
    cout << solve(stuff, dest) << endl;
  }
}
