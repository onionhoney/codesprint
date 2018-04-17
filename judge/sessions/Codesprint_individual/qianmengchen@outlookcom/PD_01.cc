//
//  main.cpp
//  Problem D
//
//  Created by ChenQianmeng on 1/28/17.
//  Copyright © 2017 ChenQianmeng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    char str[1000000];
    for (int i = 0; i < 1000000; i++)
        str[i] = 'a';
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int l, r;
        char c;
        cin >> l >> r >> c;
        for (int j = l; j <= r; j++) {
            str[j] = c;
        }
    }
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << str[a] << ' ' << str[b] << ' ' << str[c] << ' ' << str[d] << endl;
    return 0;
}
