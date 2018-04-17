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

int numPoints(int r, double x) {
  int num = 0;
  for (int i = -r-1; i <= r+1; i++) {
    for (int j = -r-1; j <= r+1; j++) {
      if ((sqrt(i*i+(j-x)*(j-x)) -r) <= 0.001) {
        num++;
      }
    }
  }
  return num;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int r;
    cin >> r;
    int cur = numPoints(r, 0);
    for (int j = 1; j < r; j++) {
      double curX = sqrt(r*r-j*j);
      double xChange = ceil(curX) - curX;
      cur = max(cur, numPoints(r,xChange));
    }
    cout << cur << endl;
  }
}
