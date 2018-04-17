//
//  main.cpp
//  Problem A
//
//  Created by ChenQianmeng on 1/28/17.
//  Copyright © 2017 ChenQianmeng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    vector<int> answers;
    cin >> t;
    for(int i = 0; i < t; i++ ) {
        int ans = 0;
        int p, n;
        cin >> p >> n;
        for(int j = 0; j < p; j++) {
            int bi, ni;
            cin >> bi >> ni;
            if (n >= ni) {
                n -= ni;
                ans += bi*ni;
            } else {
                ans += bi*n;
                n = 0;
            }
        }
        answers.push_back(ans);
    }
    
    for(auto i : answers) {
        cout << i << endl;
    }
    return 0;
}
