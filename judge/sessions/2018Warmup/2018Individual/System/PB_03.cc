//
//  main.cpp
//  codesprintTeamGame2
//
//  Created by Brian Cho on 5/19/18.
//  Copyright © 2018 Cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

ifstream fin;

void aimBot() {
  int n;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    int n, k;
    cin >> n >> k;
    cin.ignore();
    
    string input;
    getline(cin, input);
    
    char cur = input[0];
    int cur_consec = 1;
    int aim = 0;
    
    for (int i = 1; i < n; i++) {
      if (input[i] == 'H') {
        cur_consec = 0;
        cur = 'H';
      }
      else if (cur == input[i])
        cur_consec++;
      else {
        cur_consec = 1;
        cur = input[i];
      }
      
      if (cur_consec >= k) {
        cur_consec = 0;
        if (cur == 'L')
          aim++;
        else
          aim--;
      }
    }
    
    cout << aim << endl;
  }
}

void generateTestCasesForAimBot() {
  int randN, randK;
  
  randN = rand() % 99 + 2;
  randK = rand() % randN + 2;
  
  string randStr;
  for(int i = 0; i < randN; i++) {
    int randNum = rand() % 3;
    if (randNum == 0)
      randStr += "L";
    else if (randNum == 1)
      randStr += "H";
    else
      randStr += "R";
  }
  
  cout << randN << " " << randK << endl;
  cout << randStr << endl;
}

int main(int argc, const char * argv[]) {
  fin.open("/Users/briancho/Documents/cs/c++/codesprint/codesprint/aimBotInput");
  
//  for (int i = 0; i < 50; i++) {
//    generateTestCasesForAimBot();
//  }
  
  aimBot();
  
  return 0;
}
