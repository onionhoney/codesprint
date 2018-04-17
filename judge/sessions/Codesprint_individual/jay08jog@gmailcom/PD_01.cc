
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

void test (vector<tuple<int, int, char>>& instructions, vector<int>& vals) {
    for(int val : vals) {
        char c = 'a';
        for(tuple<int, int, char> t : instructions) {
            if (val >= get<0>(t) && val <= get<1>(t)) {
                c = get<2>(t);
            }
        }
        cout << c << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<tuple<int, int, char>> instructions;
    for(int i = 0; i < n; i++) {
        tuple<int, int, char> t;
        cin >> get<0>(t) >> get<1>(t) >> get<2>(t);
        instructions.push_back(t);
    }
    vector<int> vals(4);
    cin >> vals[0] >> vals[1] >> vals[2] >> vals[3];
    test(instructions, vals);
    
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

