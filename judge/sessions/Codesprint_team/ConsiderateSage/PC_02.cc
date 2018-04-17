
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
 
}
int main(int argc, const char * argv[]) {
    int t, d, n, r;
    cin >> t;
    vector<int> vals;
    for(int i = 0; i < t; i++) {
        cin >> d >> n >> r;
        for(int j = 0; j < n; j++) {
            int x, time;
            cin >> x >> time;
            if(x > r) {
                x /= time;
                while( x> r)
                { x = x/2;
                    r = x;}
            }
        }
        vals.push_back(r);
        
    }
    for(int i : vals) cout << i << endl;
 }




