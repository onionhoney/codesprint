//
//  main.cpp
//  Codesprint
//
//  Created by JackieYJC on 1/28/17.
//  Copyright © 2017 Jiachen Yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


int main() {
    //cout << "0\n";
    int nbtestcase;
    cin >> nbtestcase;
    string answer = "";
    //cout << "1\n";
    for (int i = 0; i < nbtestcase; i++) {
        int m;
        cin >> m;
        int n;
        cin >> n;
        int numlines;
        cin >> numlines;
        int horizontal;
        int vertical;
        for (int j = 0; j < numlines; j++) {
            int a;
            int b;
            int c;
            int d;
            cin >> a;
            cin >> b;
            cin >> c;
            cin >> d;
            if ((a == 0 && b == 0) || (c == 0 && d == 0))
            {
                continue;
            }
            if ((a == m && b == 0) || (c == m && d == 0))
            {
                continue;
            }
            if ((a == 0 && b == n) || (c == 0 && d == n))
            {
                continue;
            }
            if ((a == m && b == n) || (c == m && d == n))
            {
                continue;
            }
            if (a == 0){
                horizontal++;
            }
            else{
                vertical++;
            }
            
        }
        answer += to_string((horizontal+1)*(vertical+1));
        answer += "\n";
        horizontal = 0;
        vertical = 0;
    }
    // read in and store
    
    cout << answer;
    //return 0;
}

