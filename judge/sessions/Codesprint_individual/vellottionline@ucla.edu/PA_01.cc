#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int p,n;
    cin >> p >> n;
    long long beau = 0;
    int numFlowers = 0;
    for (int j = 0; j < p; j++) {
      int bi, ni;
      cin >> bi >> ni;
      int num = min(ni, n - numFlowers);
      numFlowers += num;
      beau += num * bi;
    }
    cout << beau << endl;
  }
}
