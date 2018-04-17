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

int main() {
    //read in from stdin from cin and cout
    //print a new line at end of code
    //cout << "Here:";
    int t, p, n;
    string s;
    getline(cin, s);
    t = s[0] - '0';
   // cout << t << endl;
    vector<int> vect;
    for (int j = 0; j < t; j ++) {
        string input;
        //cout << "Here:1";
        getline(cin, input);
        //cout << "hi"<< input << endl;
        p = input[0] - '0';
        n = input[2] - '0';
//        p = atoi(input[0]);
     //   cout << p << " " << n << endl;
        for (int i = 0; i < p; i ++) {
            getline(cin, input);
            int b1 = input[0] - '0';
            int n1 = input[2] - '0';
            vect.push_back(b1*n1);
        }
        
        sort(vect.begin(), vect.end()); //loop backwards
        int sum = 0, count = 0;
        for (int i = vect.size() - 1; i >= 0 && count < n; i --) {
            count ++;
            sum += vect[i];
        }
        cout << sum << endl;
    }
}