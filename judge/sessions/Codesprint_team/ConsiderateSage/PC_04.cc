
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

//
//
//int main(int argc, const char * argv[]) {
//    int t, d, n, r;
//    cin >> t;
//    vector<int> vals;
//    for(int i = 0; i < t; i++) {
//        int right;
//        cin >> d >> n >> r;
//        for(int j = 0; j < n; j++) {
//            int x, time;
//            right = r;
//            int left = 0;
//            cin >> x >> time;
//            
//            if(x >= right) {
//                x /= time;
//               while(x >= right)
//               {
//                    x = x/2;
//               }
//                right = x;
//               
//                left = right/2;
//                
//                if(right == left) {
//                    vals.push_back(-1);
//                    continue;
//                }
//            }
//        }
//        vals.push_back(right);
//        
//    }
//    for(int i : vals) cout << i << endl;
// }

int main(int argc, const char * argv[]) {
    int t, d, n, r;
    cin >> t;
    vector<int> vals;
    for(int z = 0; z < t; z++) {
        bool invalid = false;
        cin >> d >> n >> r;
        int right = r, left = 0;
        for(int i = 0; i < n; i++) {
            int x, time;
            cin >> x >> time;
            if(x >= right)
                x /= time;

            while(x >= right)
                x /= 2;
            
            if(left == x){
                vals.push_back(-1);
                invalid = true;
                break;
            }
            
            right = x;
            left = x/2;
            
        }
        if(!invalid)
            vals.push_back(right);
    }
    for(int x: vals){
        cout << x << endl;
    }
}





