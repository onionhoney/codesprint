//
//  main.cpp
//  CodeSpring2018
//
//  Created by Kyle Wong on 5/19/18.
//  Copyright © 2018 Kyle Wong. All rights reserved.
//

// C++
#include <algorithm>
#include <bitset>
//#include <complex>
//#include <deque>
//#include <exception>
//#include <fstream>
#include <functional>
//#include <iomanip>
//#include <ios>
//#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
//#include <locale>
#include <map>
//#include <memory>
//#include <new>
//#include <numeric>
//#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
//#include <stdexcept>
//#include <streambuf>
#include <string>
//#include <typeinfo>
//#include <utility>
//#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
//#include <atomic>
//#include <chrono>
//#include <condition_variable>
//#include <forward_list>
//#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
//#include <regex>
//#include <scoped_allocator>
//#include <system_error>
#include <thread>
#include <tuple>
//#include <typeindex>
//#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;
int INF = 1000000005;
long long INFF = 1000000000000000005ll;
double PI = acos(-1);

/*
 Special considerations:
 cin.ignore(1000,'\n');
 getline(cin, s);
 
 STL::iterator it;
 */

int main() {
    int n; cin >> n;
    
    vector<ll> a(n);
    ll maxx = 0;
    for(int i =0; i < n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    vector<ll> dp(maxx + 2);
    const ll MOD = 100000007LL;
    dp[1] = 1; dp[2] = 1;
    for(int i = 3;i <= maxx; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    for(int i = 0; i < n; i ++) {
        cout << dp[a[i]] << endl;
    }
}

/*
int main(int argc, const char* argv[]) {
    // faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    scanf("%d", &n);
    vector<vector<int>> arr = vector<vector<int>>(n, vector<int>(n));
    for(int x = 0; x < arr.size(); x++) {
        for(int y = 0; y < arr[x].size(); y++)
            scanf("%d", &arr[x][y]);
    }
    for(int x = 0; x < arr.size(); x++) {
        for(int y = 0; y < arr[x].size(); y++) {
            printf("%d ", arr[x][y]);
        }
        printf("\n");
    }
    return 0;
}
*/

/*
int add(int x, int y) {
 return x + y;
}
 
int main(int argc, const char* argv[]) {
    // faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, y;
    scanf("%d %d", &x, &y);
    int sum = add(x, y);
    printf("%d\n", sum);
    
    return 0;
}
*/

/*
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<vector<int>> arr = vector<vector<int>>(n, vector<int>(n));
    for(int x = 0; x < arr.size(); x++) {
        for(int y = 0; y < arr[x].size(); y++)
            cin >> arr[x][y];
    }
    for(int x = 0; x < arr.size(); x++) {
        for(int y = 0; y < arr[x].size(); y++) {
            cout << arr[x][y] << " ";
        }
        cout << endl;
    }
    return 0;
}
 */
