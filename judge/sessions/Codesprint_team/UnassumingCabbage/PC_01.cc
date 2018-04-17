#include <iostream>
#include <cassert>
#include <string.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int getInput(string s, int& x) {
    int num = 0;
    while (isdigit(s[x])) {
        num = num*10 + s[x] - '0';
        x++;
    }
    x ++;
    return num;
}
struct Light {
    int loc;
    int per;
};
int getSpeed(Light* lights, int d, int n, int rate) {
    for (int r = rate; r > 0; r --) {
        bool passed = true;
        for (int j = 0; j < n; j ++) {
            Light l = lights[j];
            int time = (l.loc/r);
            int switches = (time / l.per) % 2;
            if (switches == 1) {
                passed = false;
                break;
            }
        }
        if (passed) return r;
    }
    return -1;
}
int main() {
    int t = 0, x = 0;
    string input;
    getline(cin, input);
    t = getInput(input, x);
    for (int i = 0; i < t; i ++) {
        int d, n, r;
       // cin >> d >> n >> r;
        x= 0;
        getline(cin, input);
        d = getInput(input, x);
        n = getInput(input, x);
        r = getInput(input, x);
        Light* lights = new Light[n];
        
        for (int j = 0; j<  n; j ++) {
            int loc, per;
            x = 0;
            getline(cin, input);
            loc = getInput(input, x);
            per = getInput(input, x);
            lights[j].per = per;
            lights[j].loc = loc;
        }
//        cout << lights[0].loc << " " << lights[0].per << endl;
        int speed = getSpeed(lights, d, n, r);
        cout << speed << endl;
    }
}