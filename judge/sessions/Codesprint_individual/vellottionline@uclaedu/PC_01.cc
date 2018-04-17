#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

string path(int curX, int curY, vector<string> map) {
  map[curX][curY] = '.';
  if (curX > 0 && map[curX-1][curY] == '#') {
    return "U" + path(curX - 1, curY, map);
  }
  if (curX < (map.size() - 1) && map[curX+1][curY] == '#') {
    return "D" + path(curX + 1, curY, map);
  }
  if (curY > 0 && map[curX][curY-1] == '#') {
    return "L" + path(curX, curY - 1, map);
  }
  if (curY < (map[0].size() - 1) && map[curX][curY+1] == '#') {
    return "R" + path(curX, curY+1, map);
  }
  return "";
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int m, n;
    cin >> m >> n;
    int a, b;
    cin >> a >> b;
    vector<string > map(m, "");
    for (int i = 0; i < m; i++) {
      cin >> map[i];
    }
    a--;
    b--;
    cout << path(a, b, map) << endl;
  }
}
