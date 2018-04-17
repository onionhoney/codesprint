//
//  main.cpp
//  comp1
//
//  Created by Brian Cho on 1/28/17.
//  Copyright © 2017 Cho. All rights reserved.
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


int main(){
  long long n;
  cin >> n;
  
  for(int i = 0; i < n; i++){

    long long row, col;
    cin >> row >> col;
    vector<vector<int> > vect;
    for(int j = 0; j < row; j++){
      vector<int> temp(col, 0);
      vect.push_back(temp);
    }
    long long k;
    cin >> k;
    for(int j = 0; j < k; j++){
      long long x,y;
      cin >> x >> y;
      vect[x - 1][y - 1] = -1;
    }
    long long total = 0;
    for(int j = 0; j < row; j++){
      for(int l = 0; l < col; l++){
        if(vect[j][l] != -1){
          if(l - 1 >= 0 && vect[j][l - 1] == -1)
            total++;
          if(j - 1 >= 0 && l - 1 >= 0 && vect[j - 1][l - 1] == -1)
            total++;
          if(j - 1 >= 0 && vect[j - 1][l] == -1)
            total++;
          if(j - 1 >= 0 && l + 1 < col && vect[j - 1][l + 1] == -1)
            total++;
          if(l + 1 < col && vect[j][l + 1] == -1)
            total++;
          if(j + 1 < row && l + 1 < col && vect[j + 1][l + 1] == -1)
            total++;
          if(j + 1 < row && vect[j + 1][l] == -1)
            total++;
          if(j + 1 < row && l - 1 >= 0 && vect[j + 1][l - 1] == -1)
            total++;
        }
      }
    }
    cout << total << endl;
  }
}
