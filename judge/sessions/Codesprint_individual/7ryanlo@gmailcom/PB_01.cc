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
        string input;
    getline(cin, input);
    int x = 0;
    int     t = getInput(input, x);
    
    for (int test = 0; test < t; test ++) {
        getline(cin, input);
        x = 0;
        int m = getInput(input, x);
        int n = getInput(input, x);
        int k;
        getline(cin, input);
        x = 0;
        k = getInput(input, x);
        int v = 0, h = 0;
        for (int i = 0; i < k; i ++) {
            getline(cin, input);
            x = 0;
            int x1 = getInput(input, x);
            int y1 = getInput(input, x);
            int x2 = getInput(input, x);
            int y2 = getInput(input, x);
            if (x1 == x2) v ++;
            else {h ++;}
        }
        cout << (h+1)*(v+1) << endl;
    }
}