//
//  main.cpp
//  Problem C
//
//  Created by ChenQianmeng on 1/28/17.
//  Copyright © 2017 ChenQianmeng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    vector<string> answers;
    char map[101][101];
    for(int i = 0; i < 101; i++)
        for(int j = 0; j < 101; j++)
            map[i][j] = 0;
    for (int k = 0; k < t; k++) {
        int m, n, a, b;
        string ans;
        cin >> m >> n >> a >> b;
        for (int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                cin >> map[i][j];
        while (true) {
            if (map[a-1][b] == '#') {
                ans += 'U';
                map[a][b] = 0;
                a--;
            } else if (map[a+1][b] == '#') {
                ans += 'D';
                map[a][b] = 0;
                a++;
            } else if (map[a][b-1] == '#') {
                ans += 'L';
                map[a][b] = 0;
                b--;
            } else if (map[a][b+1] == '#') {
                ans += 'R';
                map[a][b] = 0;
                b++;
            } else
                break;
        }
        answers.push_back(ans);
    }
    
    for(auto i : answers) {
        cout << i << endl;
    }
    return 0;
}
