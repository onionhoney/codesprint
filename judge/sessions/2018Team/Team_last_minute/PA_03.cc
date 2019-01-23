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
        char last = s[0];
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == last) {
                count++;
                if (count == k) {
                    if (s[i] == 'L')
                        aim++;
                    else
                        aim--;
                    count = 0;
                }
            } else {
                count = 1;
            }
            last = s[i];
        }
        cout << aim << "\n";
    }
}
