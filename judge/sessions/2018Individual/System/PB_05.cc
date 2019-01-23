//
//  main.cpp
//  codesprint2
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

ifstream fin;

void generateHelper(int rand) {
  for (int i = 0; i < 100; i++) {
    if (i < rand)
      cout << 0;
    else if (rand == i)
      cout << 1;
    else
      cout << 2;
    
    if (i == 99)
      cout << endl;
    else
      cout << " ";
  }
}

void generateTestCasesFor2() {
  // single lock
  
  int rand1, rand2, rand3;
  rand1 = rand() % 100;
  rand2 = rand() % 100;
  rand3 = rand() % 100;
  
  generateHelper(rand1);
  generateHelper(rand2);
  generateHelper(rand3);
  
}

void inputHelper(vector<int> & output) {
  for (int i = 0; i < 100; i++) {
    cin >> output[i];
  }
}

int findHelper(vector<int> & input) {
  return lower_bound(input.begin(), input.end(), 1) - input.begin();
}

void UCLAtunneling() {
  int n;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    vector<int> input1(100);
    vector<int> input2(100);
    vector<int> input3(100);
    
    inputHelper(input1);
    inputHelper(input2);
    inputHelper(input3);
    
    cout << findHelper(input1) << " " << findHelper(input2) << " " << findHelper(input3) << endl;
  }
}



int main(int argc, const char * argv[]) {
    fin.open("/Users/briancho/Documents/cs/c++/codesprint/codesprint/UCLAtunnelingInput");
  
//  for (int i = 0; i < 50; i++)
//    generateTestCasesFor2();
  
  UCLAtunneling();
  return 0;
}
