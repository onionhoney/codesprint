//
//  main.cpp
//  Group B
//
//  Created by ChenQianmeng on 1/28/17.
//  Copyright © 2017 ChenQianmeng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define INVALID -1
#define BOMB -2

class Point {
public:
    int x;
    int y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};


int main(int argc, const char * argv[]) {
    int test_case;
    cin >> test_case;
    
    for (int k = 0; k < test_case; k++) {
        int row, col;
        cin >> row;
        cin >> col;
        
        string dummy;
        getline(cin, dummy);
        
        vector<vector<int> > map;
        vector<int> dv;
        map.push_back(dv);
        for (int k = 1; k <= row; k++) {
            vector<int> row_vec;
            row_vec.push_back(INVALID);
            for (int j = 1; j <= col; j++) {
                row_vec.push_back(0);
            }
            map.push_back(row_vec);
        }
        
        int bomb_num;
        cin >> bomb_num;
        getline(cin, dummy);
        
        
        int candy = 0;
        
        for (int i = 0; i < bomb_num; i++) {
            int b_x, b_y;
            cin >> b_x;
            cin >> b_y;
            getline(cin, dummy);
            
            if (map[b_x][b_y] > 0) {
                candy -= map[b_x][b_y];
            }
            map[b_x][b_y] = BOMB;
            
            for (int m = -1; m <= 1; m++) {
                for (int n = -1; n <= 1; n++) {
                    if (m == 0 && n == 0) continue;
                    if (b_x+m >= 1 && b_x+m <= row && b_y+n >= 1 && b_y+n <= col) {
                        switch (map[b_x+m][b_y+n]) {
                            case INVALID:
                                break;
                            case BOMB:
                                break;
                            default:
                                map[b_x+m][b_y+n]++;
                                candy++;
                                break;
                        }
                    }
                }
            }
        }
        
        cout << candy << "\n";
    }

    
    return 0;
}
