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
    int m,n;
    cin >> m >> n;
    int k;
    cin >> k;
    int numHorz = 1, numVert = 1;
    for (int j = 0; j < k; j++) {
      int x1,y1,x2,y2;
      cin >> x1 >> y1 >> x2 >> y2;
      if (x1 == x2) {
        numHorz++;
      } else {
        numVert++;
      }
    }
    cout << numHorz * numVert << endl;
  }
}
