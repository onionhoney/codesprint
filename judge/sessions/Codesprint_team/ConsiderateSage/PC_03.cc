
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

//void test(vector<pair<int, int>> s) {
// 
//}
//
//int main(int argc, const char * argv[]) {
//    int t, m, n, k;
//    cin >> t;
//    for(int i = 0; i < t; i++) {
//        
//    }
//}
int main(int argc, const char * argv[]) {
    int t, d, n, r;
    cin >> t;
    vector<int> vals;
    for(int i = 0; i < t; i++) {
        int right;
        cin >> d >> n >> r;
        for(int j = 0; j < n; j++) {
            int x, time;
            right = r;
            int left = 0;
            cin >> x >> time;
            
            if(x >= right) {
                x /= time;
                while( x > right)
                {
                    x = x/2;
                   
                    right = x;
                    if(right == left) {
                        vals.push_back(-1);
                        continue;
                    }
                    left = right/2;
                    
                }
            }
        }
        vals.push_back(right);
        
    }
    for(int i : vals) cout << i << endl;
 }




