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
bool checkName(string in) {
    int chars[256];
    for (int i = 0; i < 256; i ++) {
        chars[i] = 0;
    }
    int size = in.size();
    for (int j = 0; j < size; j ++) {
        if (!isalpha(in[j]))
            continue;
        int num = tolower(in[j]);
        chars[num] ++;
        if (chars[num] > 1) {
            return false;
        }
    }
    return true;

}
int main() {
    int t = 0, x = 0;
    string input;
    getline(cin, input);
    t = getInput(input, x);
    for (int i = 0; i < t; i ++) {
        string in;
        getline(cin, in);
        if (!checkName(in)) cout << "TRASH TALK THE USER" << endl;
        else
            cout << "INVITE TO PARTY" << endl;
    }
}