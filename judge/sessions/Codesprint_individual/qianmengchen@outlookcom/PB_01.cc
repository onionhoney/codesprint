//
//  main.cpp
//  Problem B
//
//  Created by ChenQianmeng on 1/28/17.
//  Copyright © 2017 ChenQianmeng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    vector<int> answers;
    for(int i = 0; i < t; i++) {
        int m, n, num;
        cin >> m >> n;
        cin >> num;
        int nRow = 0, nCol = 0, ans = 1;
        for(int j = 0; j < num; j++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 == x2) {
                if (x1 == m || x1 == 0)
                    continue;
                ans += (nRow + 1);
                nCol++;
            } else {
                if (y1 == n || y1 == 0)
                    continue;
                ans += (nCol + 1);
                nRow++;
            }
        }
        answers.push_back(ans);
    }
    
    for(auto i : answers) {
        cout << i << endl;
    }
    return 0;
}
