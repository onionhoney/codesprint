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
        int n, p, q;
        cin >> n >> p >> q;
        vector<int> a(p);
        for (int i = 0; i < p; i++) cin >> a[i];
        vector<int> b(q);
        for (int i = 0; i < q; i++) cin >> b[i];
        
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        
        int unhappy = 0;
        while (n--) {
            if (a.empty() || b.empty())
                break;
            if (a[0] > b[0]) {
                unhappy += a[0];
                a[0]--;
                sort(a.begin(), a.end(), greater<int>());
                b[b.size() - 1]--;
                if (b[b.size() - 1] == 0)
                    b.pop_back();
            } else {
                unhappy += b[0];
                b[0]--;
                sort(b.begin(), b.end(), greater<int>());
                a[a.size() - 1]--;
                if (a[a.size() - 1] == 0)
                    a.pop_back();
            }
        }
        
        cout << unhappy << "\n";
    }
}
