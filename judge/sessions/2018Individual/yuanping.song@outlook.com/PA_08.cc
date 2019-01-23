//
//  Problem_2.cpp
//  LA Code Sprint
//
//  Created by Yuanping Song on 5/20/18.
//  Copyright © 2018 Yuanping Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int numLocks = 0;
    cin >> numLocks;
    while (numLocks) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 100; j++) {
                int temp;
                cin >> temp;
                if (temp == 1) {
                    cout << j;
                }
            }
            if (i != 3) {
                cout << " ";
            }
        }
        cout << endl;
        numLocks--;
    }
}
