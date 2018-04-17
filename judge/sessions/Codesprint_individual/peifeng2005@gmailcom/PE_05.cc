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
    int n;
    cin >> n;
    vector<long long> ans;
    for(int z = 0; z < n; z++){
        int k;
        cin >> k;
        long long amount = 1;
        for(int i = 0; i < k; i++){
            long long stair;
            cin >> stair;
            while(stair > 30){
                amount = (((amount % 10007) * ((1 << 30) % 10007)) % 10007);
                stair -= 30;
            }
            amount = (((amount % 10007) * ((1 << (stair-1)) % 10007)) % 10007);
            amount %= 10007;
        }
        ans.push_back(amount);
    }
    for(long long x : ans){
        cout << x << endl;
    }
}