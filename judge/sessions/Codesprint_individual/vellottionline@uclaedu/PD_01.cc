#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

char solve(int i, vector<vector<int> > stuff, vector<char> chars) {
  char a = 'a';
  for (int j = 0; j < stuff.size(); j++) {
    int l = stuff[j][0], r = stuff[j][1];
     if (i >= l && r >= i) {
      a = chars[j];
    }
  }
  return a;
}
int main() {
  int n;
  cin >> n;
  vector<vector<int> > stuff(n, vector<int>(2, 0));
  vector<char> chars(n, ' ');
  for (int i = 0; i < n; i++) {
    cin >> stuff[i][0] >> stuff[i][1] >> chars[i];
    //cout << chars[i] << endl;
  }
  int i1, i2, i3, i4;
  cin >> i1 >> i2 >> i3 >> i4;
  cout << solve(i1, stuff,chars) << ' '
    << solve(i2, stuff,chars) << ' '
    << solve(i3, stuff,chars) << ' '
     << solve(i4, stuff,chars) << ' ' << endl;
}
