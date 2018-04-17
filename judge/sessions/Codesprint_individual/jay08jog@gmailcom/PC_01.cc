
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

void DFS (vector<vector<char>>& path, int a, int b) {
    if(b - 1 >= 0 && path[a][b-1] == '#') {
        cout << "L";
        path[a][b-1] = '.';
        DFS(path, a, b-1);
    }
    else if(b + 1 < path[0].size() && path[a][b+1] == '#') {
        cout << "R";
        path[a][b+1] = '.';
        DFS(path, a, b+1);
    }
    else if(a - 1 >= 0 && path[a-1][b] == '#') {
        cout << "U";
        path[a-1][b] = '.';
        DFS(path, a-1, b);
    }
    else if(a + 1 < path.size() && path[a+1][b] == '#') {
        cout << "D";
        path[a+1][b] = '.';
        DFS(path, a+1, b);
    }
}
void test (vector<vector<char>>& path, int a, int b) {
    a --; b--;
    DFS(path, a, b);
    cout << endl;
}
int main(int argc, const char * argv[]) {
    int t, m, n;
    cin >> t;
    vector<vector<vector<char>>> grids;
    vector<pair<int, int>> starts;
    for(int i = 0; i < t; i++) {
        cin >> m >> n;
        pair<int, int> p;
        
        cin >> p.first >> p.second;
        starts.push_back(p);
        
        vector<vector<char>> grid;
        
        for(int j = 0; j < m; j++) {
            vector<char> line;
            for(int k = 0; k < n; k++) {
                char c;
                cin >> c;
                line.push_back(c);
            }
            grid.push_back(line);
        }
        grids.push_back(grid);
    }
    for(int i = 0; i < t; i++) {
        test(grids[i], starts[i].first, starts[i].second);
    }
}
