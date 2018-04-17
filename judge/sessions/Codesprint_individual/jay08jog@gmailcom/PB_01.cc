
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
void test (vector<vector<int>>& points) {
    int horiz = 0, vert = 0;
    for(vector<int> point : points) {
        if(point[0] == point[2]) vert++;
        else horiz ++;
    }
    cout << (horiz+1) * (vert+1) << endl;

}
int main(int argc, const char * argv[]) {
    int t, m, n, k;
    cin >> t;
    vector<vector<vector<int>>> points;
    for(int i = 0; i < t; i++) {
        cin >> m >> n >> k;
        vector<vector<int>> lines;
        for(int i = 0; i < k; i++) {
            vector<int> v(4);
            cin >> v[0] >>  v[1] >> v[2] >> v[3];
            lines.push_back(v);
        }
        points.push_back(lines);
    }
    
    for(int i = 0; i < t; i++) {
        test(points[i]);
    }
}
