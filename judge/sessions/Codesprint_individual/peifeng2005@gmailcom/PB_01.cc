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

int main(int argc, const char * argv[]) {
    int t, k, m, n;
    cin >> t;
    vector<int> ans;
    for(int j = 0; j < t; j++){
        int horizontals = 0, verticals = 0;
        cin >> m >> n >> k;
        for(int i = 0; i < k; i++){
            int x_0, x_1, y_0, y_1;
            cin >> x_0 >> y_0 >> x_1 >> y_1;
            if(x_0 == x_1)
                verticals++;
            if(y_0 == y_1)
                horizontals++;
        }
        ans.push_back((horizontals+1)*(verticals+1));
    }
    for(int x : ans){
        cout << x << endl;
    }
}