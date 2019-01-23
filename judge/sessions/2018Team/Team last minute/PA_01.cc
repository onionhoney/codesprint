//
//  main.cpp
//  Team Round
//
//  Created by Aaron Yoo on 5/20/18.
//  Copyright © 2018 Aaron Yoo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int aim = 0;
        char last = ' ';
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == last) {
                count++;
                if (count == 2) {
                    if (last == 'L') {
                        aim++;
                    } else if (last == 'R') {
                        aim--;
                    }
                    count = 0;
                }
            } else {
                last = s[i];
                count = 0;
            }
        }
        cout << aim << "\n";
    }
}
