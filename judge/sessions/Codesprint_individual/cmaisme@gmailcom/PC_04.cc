//
//  main.cpp
//  CodeSprintLA
//
//  Created by Christopher Aziz on 1/28/17.
//  Copyright © 2017 Christopher Aziz. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// include newline after each cout
string explore(int sR,int sC, string& s, vector<vector<char> > &arr, int row, int col) {
    if(sR + 1 != row && arr[sR+1][sC] == '#') {
        arr[sR+1][sC] = 'X';
        s = s + "D";
        return explore(sR+1, sC, s, arr, row, col);
    }
    if(sR - 1 != -1 && arr[sR-1][sC] == '#') {
        arr[sR-1][sC] = 'X';
        s = s + "U";
        return explore(sR-1, sC, s, arr, row, col);
    }
    if(sC + 1 != col && arr[sR][sC+1] == '#') {
        arr[sR][sC+1] = 'X';
        s = s + "R";
        return explore(sR, sC+1, s, arr, row, col);
    }
    if(sC - 1 != -1 && arr[sR][sC-1] == '#') {
        arr[sR][sC-1] = 'X';
        s = s + "L";
        return explore(sR, sC-1, s, arr, row, col);
    }
    return s;
}
int main() {
    int t;
    cin >> t;
    
    
    
    while(t--) {
        
        int row;
        int col;
        cin >> row;
        cin >> col;
        int startR = -1;
        int startC = -1;
        cin >> startR;
        cin >> startC;
        startC--;
        startR--;
        std::vector< std::vector<char> > arr(row, std::vector<char>(col,0)) ;

        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {
                
                cin >> arr[r][c];

            }
        }
        
        string answer = "";
        string actual;
        actual = explore(startR, startC, answer, arr, row, col);
        cout << actual;
        
        
        
        
    }
    
    return 0;
    
}


