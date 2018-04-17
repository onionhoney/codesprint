#include <iostream>
#include <cassert>
#include <string.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


//struct flower {
//    int b;
//    int n;
//};
int getInput(string s, int& x) {
    int num = 0;
    while (isdigit(s[x])) {
        num = num*10 + s[x] - '0';
        x++;
    }
    x ++;
    return num;
}

int main() {
    //read in from stdin from cin and cout
    //print a new line at end of code
    char a[1000000];
    for (int i = 0; i < 1000000; i ++) {
        a[i] = 'a';
    }
    int n = 0;
    cin >> n;
    for (int i = 0  ; i < n; i ++) {
        int l, r;
        char c;
        cin >> l >> r >> c;
        for (int j = 0; j < 1000000; j ++) {
            if (j >= l && j <= r)
                a[j] = c;
        }
    }
    int i0, i1, i2, i3;
    cin >> i0 >> i1 >> i2 >> i3;
    cout << a[i0] << " " << a[i1] << " " << a[i2] << " " << a[i3] << " " << endl;
//        string input;
//    getline(cin, input);
//    int x = 0;
//    int     t = getInput(input, x);
//    
//    for (int test = 0; test < t; test ++) {
//        getline(cin, input);
//        x = 0;
//        int m = 0;
//        m = getInput(input, x); //rows
//        int n = getInput(input, x);// cols
//        int a, b;
//        getline(cin, input);
//        x = 0;
//        a = getInput(input, x) - 1;
//        b = getInput(input, x) - 1;
//        string* map = new string[m];
//        for (int i = 0; i < m; i ++) {
//            getline(cin, input);
//            map[i] = input;
//        }
//        string dir = "";
//        int r = a, c = b;
//        
//        while(1) {
//            //north
//            map[r][c] = '.';
////            cout << endl;
////            for (int i = 0; i < m; i ++) {
////                
////                cout << map[i] << endl;
////            }
//            
//            
//            if (r - 1 >= 0 && map[r-1][c] == '#')
//            {
//                dir += "U";
//                r --;
//            }
//            //south
//            else if (r + 1 < m && map[r+1][c] == '#') {
//                dir += "D";
//                r ++;
//            }
//            //west
//            else if (c - 1 >= 0 && map[r][c - 1] == '#')
//            {
//                dir += "L";
//                c --;
//            }
//            //east
//            else if (c + 1 < n && map[r][c+1] == '#') {
//                dir += "R";
//                c ++;
//            }
//            else {
//                break;
//            }
//            
//            
//        }
//        cout << dir << endl;
//
//    }
}