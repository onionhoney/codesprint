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

bool inbound(int x, int y, int m, int n){
    return (x >= 0 && x < m) && (y >= 0 && y < n);
}

void traverse(vector<vector<char>>& v, vector<char>& dir, int x, int y, int m, int n){
    if(inbound(x+1, y, m, n) && v[x+1][y] == '#'){
        dir.push_back('D');
        v[x+1][y] = '.';
        traverse(v, dir, x+1, y, m, n);
        return;
    }
    else if(inbound(x, y+1, m, n) && v[x][y+1] == '#'){
        dir.push_back('R');
        v[x][y+1] = '.';
        traverse(v, dir, x, y+1, m, n);
        return;

    }
    else if(inbound(x-1, y, m, n) && v[x-1][y] == '#'){
        dir.push_back('U');
        v[x-1][y] = '.';

        traverse(v, dir, x-1, y, m, n);
        return;


    }
    else if(inbound(x, y-1, m, n) && v[x][y-1] == '#'){
        dir.push_back('L');
        v[x][y-1] = '.';

        traverse(v, dir, x, y-1, m, n);
        return;


    }
    else
        return;
}

int main(int argc, const char * argv[]) {
    int t, k, m, n;
    cin >> t;
    vector<vector<char>> directions(t);
    for(int z = 0; z < t; z++){
        int a, b;
        cin >> m >> n >> a >> b;
        vector<vector<char>> v(m, vector<char>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> v[i][j];
            }
        }
        traverse(v, directions[z], a-1, b-1, m, n);
    }
    for(auto v_ : directions){
        for(char c: v_){
            cout << c;
        }
        cout << endl;
    }
}