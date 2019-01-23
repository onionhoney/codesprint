//
//  main.cpp
//  codesprint
//
//  Created by Brian Cho on 5/16/18.
//  Copyright © 2018 Cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>

using namespace std;

void smallbergsDilemma() {
  ifstream fin;
  fin.open("/Users/briancho/Documents/cs/c++/codesprint/codesprint/smallbergDilemmaInput");
  
  int t;
  fin >> t;
  
  for (int i = 0; i < t; i++) {
    int n;
    fin >> n;
    
    int m1, m2;
    fin >> m1 >> m2;
    
    vector<int> cs31(m1);
    vector<int> cs32(m2);
    
    for (int i = 0; i < m1; i++) {
      fin >> cs31[i];
    }
    
    for (int i = 0; i < m2; i++) {
      fin >> cs32[i];
    }
    
    int cur_max = 0;
    
    for (int i = 0; i < m1; i++) {
      for (int j = 0; j < m2; j++) {
        if (cs31[i] + cs32[j] <= n) {
          cur_max = max(cur_max, cs31[i] + cs32[j]);
        }
      }
    }
    
    cout << cur_max << endl;
  }
  

}

void generateTestCasesFor1() {
  int randJump = rand() % 999 + 2;
  
  int randCS31 = rand() % 100 + 1;
  int randCS32 = rand() % 100 + 1;
  
  vector<int> CS31(randCS31);
  vector<int> CS32(randCS32);
  
  for (int i = 0; i < randCS31 - 1; i++) {
    CS31[i] = rand() % 1000 + 1;
  }
  
  for (int i = 0; i < randCS32 - 1; i++) {
    CS32[i] = rand() % 1000 + 1;
  }
  
  int randNum = rand() % (randJump - 1) + 1;
  CS31[randCS31 - 1] = randNum;
  CS32[randCS32 - 1] = rand() % (randJump - randNum) + 1;
  
  cout << randJump << endl;
  cout << randCS31 << " " << randCS32 << endl;
  for (int i = 0; i < randCS31; i++) {
    cout << CS31[i];
    if (i == randCS31 - 1)
      cout << endl;
    else
      cout << " ";
  }
  
  for (int i = 0; i < randCS32; i++) {
    cout << CS32[i];
    if (i == randCS32 - 1)
      cout << endl;
    else
      cout << " ";
  }
}

int main(int argc, const char * argv[]) {
  smallbergsDilemma();
  
//  for (int i = 0; i < 10; i++) {
//    generateTestCasesFor1();
//  }
  
  
  return 0;
}
