
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void test(string& s) {
    int count = 0;
    int chars[26] = {0};
    for(char c: s) {
        if(isalpha(c)) chars[tolower(c)-'a']++;
    }
    for(int i = 0; i < 26; i++)
        if(chars[i] > 0) count++;
    if(count % 2 == 0) cout << "INVITE TO PARTY" << endl;
    else cout << "TRASH TALK TO THE USER" << endl;
}
int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    cin.ignore();
    vector<string> inputs;
    for(int i = 0; i < t; i++) {
        string s;
        getline(cin, s);
        inputs.push_back(s);
    }
    for(int i = 0; i < t; i++)
        test(inputs[i]);
 }




