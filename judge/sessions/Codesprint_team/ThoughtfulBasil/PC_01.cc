//
//  main.cpp
//  Group C
//
//  Created by Yizhu Zhang on 1/28/17.
//  Copyright © 2017 Yizhu Zhang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool ifPass(int s, int l, int p){
    double q = l/s;
    int x = q/p;
    if (x % 2 == 0)
        return true;
    else
        return false;
}

int main(int argc, const char * argv[]) {
    int t;
    vector<int> answers;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        bool speeds[101];
        for (int i = 0; i < 101; i++)
            speeds[i] = true;
        int d, n, r;
        cin >> d >> n >> r;
        for (int i = 0; i < n; i++) {
            int l, p;
            cin >> l >> p;
            for (int j = r; j > 0; j--) {
                if (speeds[j] == false)
                    continue;
                if (!ifPass(j, l, p))
                    speeds[j] = false;
            }
        }
        for (int j = r; j > 0; j--) {
            if (speeds[j]){
                answers.push_back(j);
                break;
            }
        }
    }
    
    for(auto i : answers) {
        cout << i << endl;
    }
    return 0;
}
