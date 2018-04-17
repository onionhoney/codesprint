
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
void test (vector<pair<int, int>>& flowers, int n) {
    int beauty = 0;
    for(int i = 0; i < flowers.size() && n>0; i++) {
        for(int j = 0; j < flowers[i].second && n>0; j++) {
            n --;
            beauty += flowers[i].first;
        }
    }
    cout << beauty << endl;

}
int main(int argc, const char * argv[]) {
    int t, p, n;
    cin >> t;
    vector<vector<pair<int,int>>> flowers;
    vector<int> ns;
    for(int i = 0; i < t; i++) {
        vector<pair<int, int>> v;
        cin >> p >> n;
        ns.push_back(n);
        for(int i = 0; i < p; i++) {
            pair<int,int> pa;
            cin >> pa.first >> pa.second;
            v.push_back(pa);
        }
        flowers.push_back(v);
    }
    for(int i = 0; i < flowers.size(); i++) {
        test(flowers[i], ns[i]);
    }
}
