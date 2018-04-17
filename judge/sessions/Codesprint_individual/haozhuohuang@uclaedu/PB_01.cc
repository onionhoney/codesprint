//
//  main.cpp
//  test
//
//  Created by Haozhuo Huang on 28/01/2017.
//  Copyright © 2017 Haozhuo Huang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int test_case = 0;
    cin >> test_case;
    for(int j = 0; j < test_case; j++){
        int h = 0; int v = 0;
        cin >> h >> v;
        int num_line = 0;
        cin >> num_line;
        int d_h = 0;
        int d_v = 0;
        int total = 1;
        for(int k = 0; k < num_line; k++){
            int x1 = -1; int x2 = -1; int x3 = -1; int x4 = -1;
            cin >> x1 >> x2 >> x3 >> x4;
            if(x2 == 0){
                total += (d_h + 1);
                d_v++;
            }
            else if(x1==0){
                total += (d_v + 1);
                d_h++;
            }
        }
        cout << total << endl;
    }
}
