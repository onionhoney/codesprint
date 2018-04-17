//
//  main.cpp
//  Problem D
//
//  Created by ChenQianmeng on 1/28/17.
//  Copyright © 2017 ChenQianmeng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct operation {
    int l;
    int r;
    char c;
    
    operation(int left, int right, int character){
        l = left;
        r = right;
        c = character;
    }
};

int main(int argc, const char * argv[]) {
    vector<operation> ops;
    ops.push_back(operation(0, 1000001, 'a'));
    string ans;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int l, r;
        char c;
        cin >> l >> r >> c;
        ops.push_back(operation(l, r, c));
    }
    
    for (int i = 0; i < 4; i++) {
        int loc;
        cin >> loc;
        for (int j = ops.size()-1; j >= 0; j--) {
            if (loc >= ops[j].l && loc <= ops[j].r) {
                ans += ops[j].c;
                ans += ' ';
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
