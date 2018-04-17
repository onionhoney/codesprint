
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

vector<int> tribonacci;
void compute(int n) {
    for(unsigned long i = tribonacci.size(); i <= n; i++)
        tribonacci[i] = tribonacci[i-1]*tribonacci[i-2]*tribonacci[i-3];
}
void test (vector<int>& stairs) {
    long long val = 1;
    for(int i = 0; i < stairs.size(); i++) {
        if(stairs.size() > tribonacci.size())
            compute(stairs.size());
        val *= tribonacci[stairs[i]];
    }
    cout << val % 10007 << endl;
}

int main(int argc, const char * argv[]) {
    tribonacci.push_back(0);
    tribonacci.push_back(1);//1
    tribonacci.push_back(2);//2
    tribonacci.push_back(4);//3
    
    int t, n;
    cin >> t;
    vector<vector<int>> stairs;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> stair;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            stair.push_back(x);
        }
        stairs.push_back(stair);
    }
    for(int i = 0; i < t; i++)
        test(stairs[i]);
    
//    cin >> t;
//    vector<vector<vector<char>>> grids;
//    vector<pair<int, int>> starts;
//    for(int i = 0; i < t; i++) {
//        cin >> m >> n;
//        pair<int, int> p;
//        
//        cin >> p.first >> p.second;
//        starts.push_back(p);
//        
//        vector<vector<char>> grid;
//        
//        for(int j = 0; j < m; j++) {
//            vector<char> line;
//            for(int k = 0; k < n; k++) {
//                char c;
//                cin >> c;
//                line.push_back(c);
//            }
//            grid.push_back(line);
//        }
//        grids.push_back(grid);
//    }
//    for(int i = 0; i < t; i++) {
//        test(grids[i], starts[i].first, starts[i].second);
//    }
}


