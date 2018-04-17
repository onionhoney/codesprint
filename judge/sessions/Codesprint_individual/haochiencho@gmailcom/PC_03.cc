//
//  main.cpp
//  Practice_1
//
//  Created by Brian Cho on 11/15/16.
//  Copyright © 2016 Cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <math.h>
#include <set>
#include <utility>
#include <functional>

using namespace std;


//int main(int argc, const char* argv[]){
//  long long n;
//  cin >> n;
//  for(int i = 0; i < n; i++){
//    long long type, num;
//    cin >> type >> num;
//    long long sum = 0;
//    for(int j = 0; j < type; j++){
//      long long beauty, amount;
//      cin >> beauty >> amount;
//      while(num > 0 && amount > 0){
//        sum += beauty;
//        amount--;
//        num--;
//      }
//    }
//    cout << sum << endl;
//  }
//}

//int main(){
//  long long n;
//  cin >> n;
//  for (int i = 0; i < n; i++) {
//    long long discard;
//    cin >> discard >> discard;
//    long long numLines;
//    cin >> numLines;
//    long long horiz = 1;
//    long long vert = 1;
//    for(int j = 0; j < numLines; j++){
//      long long x1, y1, x2, y2;
//      cin >> x1 >> y1 >> x2 >> y2;
//      if(x1 == x2)
//        vert++;
//      else if(y1 == y2)
//        horiz++;
//    }
//    cout << vert * horiz << endl;
//  }
//}

string path(long long x, long long y, vector<string> & map, string& curPath){
  long long row = map.size();
  long long col = map[0].length();
  if(x + 1 < row && map[x + 1][y] == '#'){
    curPath += 'D';
    map[x][y] = '.';
    return path(x + 1, y, map, curPath);
  }
  else if(x - 1 >= 0 && map[x - 1][y] == '#'){
    curPath += 'U';
    map[x][y] = '.';
    return path(x - 1, y, map, curPath);
  }
  else if(y + 1 < col && map[x][y + 1] == '#'){
    curPath += 'R';
    map[x][y] = '.';
    return path(x, y + 1, map, curPath);
  }
  else if(y - 1 >= 0 && map[x][y - 1] == '#'){
    curPath += 'L';
    map[x][y] = '.';
    return path(x, y - 1, map, curPath);
  }
  return curPath;
}

int main(){
  long long n;
  cin >> n;
  long long row, col;
  cin >> row >> col;
  long long x, y;
  cin >> x >> y;
  
  for(int i = 0; i < n; i++){
    vector<string> map;
    for(int j = 0; j < row; j++){
      string input;
      cin >> input;
      map.push_back(input);
    }
    string curPath;
    string result = path(x - 1, y - 1, map, curPath);
    cout << curPath << endl;
  }
}
