//
//  main.cpp
//  codesprint
//
//  Created by Kyle Hess on 5/20/18.
//  Copyright © 2018 Kyle Hess. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;



/*int main() {
    
}*/







int main() {
    int t;
    cin >> t;
    int n;
    cin >> n;
    int p,q;
    cin >> p >> q;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < p; ++i) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < q; ++i) {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    
    vector<int> sums;
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < q; ++j) {
            sums.push_back(a[p]+b[q]);
        }
    }
    
    int maxstud = 0;
    for (int i = 0; i < p*q; ++i) {
        if (sums[i] <= n) maxstud = max(sums[i], maxstud);
    }
    
    cout << maxstud;
    
}














































