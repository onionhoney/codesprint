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

const int MOD = 10007;

int modExp(int a, int e) {
    int accumulate = 1, cache = a % MOD;
    while(e != 0){
        if(e & 0x1){
            accumulate = (accumulate * cache) % MOD;
        }
        cache = (cache * cache) % MOD;
        e >>= 1;
    }
    return accumulate;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<long long> ans;
    for(int z = 0; z < n; z++){
        int k;
        cin >> k;
        int stairs = 0;
        for(int i = 0; i < k; i++){
            int stair;
            cin >> stair;
            
            stairs += stair-1;
        }
        ans.push_back(modExp(2, stairs));
    }
    for(long long x : ans){
        cout << x << endl;
    }
}