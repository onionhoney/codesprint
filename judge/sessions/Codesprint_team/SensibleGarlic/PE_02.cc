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

int numPoints(int r) {
  int num = 0;
  for (int i = -r; i <= r; i++) {
    int minX = sqrt(r*r-i*i);
    num += (2*minX + 1);
  }
  return num;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int r;
    cin >> r;
    int cur = numPoints(r);
    vector<double> distances;
    for (int j = 1; j <= r; j++) {
      double curX = sqrt(1.0*(r*r-j*j));
      double xChange = ceil(curX)*1.0 - curX*1.0;
      if (xChange == 0) {
        xChange = 1;
      }
      distances.push_back(xChange);
    }
    sort(distances.begin(), distances.end());
    int maxNum = 0;
    for (int j = 0; j < distances.size(); j++) {
      double curDist = distances[j];
      if (curDist >= 0.5) continue;
      int curNum = j + 1;
      int k;
      for (k = distances.size() - 1; k >= 0; k--) {
        if (curDist + distances[k] < 1) {
          break;
        }
      }
      curNum -= (distances.size() - k - 1);
      maxNum = max(maxNum, curNum);
    }
    cout << cur + 2*maxNum - (maxNum == 0 ? 0 : 1) << endl;
  }
}
