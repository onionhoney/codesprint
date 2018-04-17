#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int minDistance(vector<vector<int> > distances, int vStart, int vEnd) {
  vector<bool> marked(distances.size(), false);
  marked[vStart] = true;
  while (!marked[vEnd]) {
    vector<int> goodVertices;
    for (int i = 0; i < distances.size(); i++) {
      if (marked[i]) goodVertices.push_back(i);
    }
    int bestVertex = -1, bestDistance = INT_MAX;
    for (int i = 0; i < distances.size(); i++) {
      if (marked[i]) continue;
      if (distances[vStart][i] < bestDistance) {
        bestVertex = i;
        bestDistance = distances[vStart][i];
      }
    }
    marked[bestVertex] = true;
    for (int i = 0; i < distances.size(); i++) {
      distances[vStart][i] = min(distances[vStart][i], distances[vStart][bestVe\
rtex] + distances[bestVertex][i]);
      //cout << distances[vStart][i] << " ";
    }
    //cout << distances[2][1] << endl;
    //cout << endl;
  }
  return distances[vStart][vEnd];
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n,k,r;
    cin >> n >> k >> r;
    vector<vector<int> > distances(n, vector<int>(n, INT_MAX/1000));
    vector<vector<int> > wormholes(k, vector<int>(2, 0));
    for (int j = 0; j < k; j++) {
      cin >> wormholes[j][0] >> wormholes[j][1];
      wormholes[j][0]--;
    }
    for (int j = 0; j < r; j++) {
      int ai,bi,ti;
      cin >> ai >> bi >> ti;
      ai--;
      bi--;
      distances[ai][bi] = min(distances[ai][bi], ti);
      distances[bi][ai] = distances[ai][bi];
    }
    for (int j = 0; j < k; j++) {
      for (int p = 0; p < k; p++) {
        if (p == j) continue;
        int p1 = wormholes[j][0], p2 = wormholes[p][0], tim = wormholes[j][i];
        distances[p2][p1] = min(distances[p1][p2], tim);
      }
    }
    cout << minDistance(distances, 0, n - 1) << endl;
  }
}


