//
//  main.cpp
//  Problem E
//
//  Created by ChenQianmeng on 1/28/17.
//  Copyright © 2017 ChenQianmeng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

long climb(long steps){
    if (steps == 1 || steps == 0)
        return 1;
    else if (steps < 1)
        return 0;
    long ans = 0;
    for (int i = 1; i <= 3; i++) {
        if (steps - i >= 0) {
            ans += climb(steps - i);
        } else
            break;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<int> answers;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long ans = 1;
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int steps;
            cin >> steps;
            ans *= climb(steps);
        }
        answers.push_back(ans % 10007);
    }
    
    for(auto i : answers) {
        cout << i << endl;
    }
    return 0;
}
