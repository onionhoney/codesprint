//
//  main.cpp
//  codesprintElevator
//
//  Created by Brian Cho on 5/19/18.
//  Copyright © 2018 Cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
  int t;
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    int a, b, c, f, p;
    cin >> a >> b >> c >> f >> p;
    
    
    
    vector<int> peopleTemp(p);
    
    for (int i = 0; i < p; i++) {
      cin >> peopleTemp[i];
    }
    
    sort(peopleTemp.begin(), peopleTemp.end());
    
    vector<int> people;
    int prev = peopleTemp[0];
    people.push_back(prev);
    
    for(int i = 1; i < p; i++) {
      if (prev == peopleTemp[i])
        continue;
      else {
        prev = peopleTemp[i];
        if (prev == 1)
          continue;
        
        people.push_back(prev);
      }
    }
    
    long long cur_time = 0;
    int cur_floor = 1;
    
    for (int i = 0; i < people.size(); i++) {
      cur_time += (people[i] - cur_floor) * a + b;
      
      cur_floor = people[i];
    }
    
    cur_time -= b;
    long long min_time = cur_time;
    
    for (int i = 0; i < people.size() - 1; i++) {
      min_time = min((int) min_time, max((int) cur_time - b * (i + 1), c * (people[i] - 1)));
    }
    
    cout << min((int) min_time, (people[people.size() - 1] - 1) * c) << endl;
  }
  
  return 0;
}
