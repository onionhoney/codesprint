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

int maxPokes(int cur, vector<vector<bool> >& maps, vector<bool>& pokestops) {
  int val = 0;
  for (int i = 0; i < maps.size(); i++) {
    if (maps[cur][i]) {
      maps[cur][i] = false;
      maps[i][cur] = false;
      val = max(val, maxPokes(i,maps,pokestops));
      maps[cur][i] = true;
      maps[i][cur] = true;
    }
  }
  return val + (pokestops[cur] ? 1 : 0);
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n,p,e;
    cin >> n >> p >> e;
    vector<bool> pokestops(n, false);
    for (int j = 0; j < p; j++) {
      int r;
      cin >> r;
      pokestops[r] = true;
    }
    vector<vector<bool> > maps(n, vector<bool>(n, false));
    for (int j = 0; j < e; j++) {
      int a,b;
      cin >> a >> b;
      maps[a][b] = true;
      maps[b][a] = true;
    }
    cout << maxPokes(0, maps, pokestops) << endl;
  }
}
