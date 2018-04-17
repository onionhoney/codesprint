#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> all(1000001, 0);
int curSolved = 0;
int solve(int num) {
  return all[num];
}
int main() {
  int t;
  all[0] = 1;
  for (int i = 1; i < all.size(); i++) {
    for (int j = max(0, i - 3); j < i; j++) {
      all[i] += all[j];
      all[i] %= 10007;
    }
  }
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int num = 1;
    for (int j = 0; j < n; j++) {
      int r;
      cin >> r;
      num *= all[r];
      num %= 10007;
    }
    cout << num << endl;
  }
}
