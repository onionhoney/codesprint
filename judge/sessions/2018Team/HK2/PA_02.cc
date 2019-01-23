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
const ll MOD = 100000007LL;

/*
 Special considerations:
 cin.ignore(1000,'\n');
 getline(cin, s);
 
 STL::iterator it;
 */

int main() {
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++) {
        int k, n;
        cin >> n >> k;
        cin.ignore(1000, '\n');
        string s;
        getline(cin, s);
        int loc = 0;
        for(int x = 0; x < s.size() - k; x++) {
            if(s[x] == 'H')
                continue;
            bool adjust = true;
            for(int y = x; y < x + k - 1; y++) {
                if(s[y] == s[y+1])
                    continue;
                else {
                    adjust = false;
                    break;
                }
            }
            if(adjust) {
                if(s[x] == 'L')
                    loc++;
                else if(s[x] == 'R')
                    loc--;
                x += k - 1;
            }
        }
        cout << loc << endl;
    }
}

/*
int lengths(string s, int k) {
    map<char, int> m;
    int left = 0;
    int maxx = k;
    for(int z = 0; z < s.size(); z++) {
        m[s[z]]++;
        if(m.size() > k) {
            maxx = max(maxx, z-left);
            while(m.size() > k) {
                if(m[s[left]]==1)
                    m.erase(m.find(s[left]));
                else
                    m[s[left]]--;
                left++;
            }
        }
    }
    int ka = s.size()-left;
    maxx = max(maxx, ka);
    return maxx;
}

int main() {
    int cases;
    cin >> cases;
    for(int x = 0; x < cases; x++) {
        int N, C;
        string s;
        cin >> N >> C;
        cin.ignore(1000, '\n');
        getline(cin, s);
        vector<int> arr = {1, 2, 3, 4, 5};
        int ans = 0;
        for(int y = 0; y < arr.size(); y++) {
            int maxx = lengths(s, arr[y]);
            int dist = 1 << (arr[y]+1);
            if(maxx <= dist) {
                if(arr[y] * maxx <= C)
                    ans = max(ans, arr[y]*maxx);
            }
            //if(maxx <= (1 << arr[y]) && arr[y] * maxx <= C)
            //    ans = max(ans, arr[y]*maxx);
        }
        cout << ans << endl;
    }
}
 */

/*
int main() {
    int t;
    cin >> t;
    for(int x = 0; x < t; x++) {
        int n;
        cin >> n;
        int arrsize = 1 << n;
        vector<char> arr(arrsize);
        for(int y = 0; y < arr.size(); y++) {
            cin >> arr[y];
        }
        bool isA = false;
        bool isB = false;
        char whoseTurn = 'A';
        for(int y = 0; y < arr.size() - 1; y++) {
            if(arr[y] == 'A' && arr[y+1] == 'A') {
                isA = true;
            }
            if(arr[y] == 'B' && arr[y+1] == 'B') {
                isB = true;
            }
        }
        if(n % 2 == 1) {
            if(isA)
                cout << "A" << endl;
            else if(isB)
                cout << "B" << endl;
            else
                cout << "A" << endl;
        }
        else {
            if(isB)
                cout << "B" << endl;
            else if(isA)
                cout << "A" << endl;
            else
                cout << "B" << endl;
        }
    }
}
 */

/*
int main() {
    int t;
    cin >> t;
    for(int x = 0; x < t; x++) {
        int a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        int f;
        cin >> f;
        int p;
        cin >> p;
        vector<int> arr(p, 0);
        for(int y = 0; y < arr.size(); y++) {
            cin >> arr[y];
        }
        // some dp stuff
        
    }
}
 */

/*
int main() {
    int c;
    cin >> c;
    for(int x = 0; x < c; x++) {
        int n, l, k;
        cin >> n >> l >> k;
        vector<vector<int>> passages = vector<vector<int>>(l, vector<int>(2));
        vector<vector<int>> adj = vector<vector<int>>(n, vector<int>(n));
        for(int y = 0; y < l; y++) {
            cin >> passages[y][0];
            cin >> passages[y][1];
        }
        vector<vector<int>> tmp;
        
    }
}
 */

// Problem B
/*
int main() {
    int n;
    cin >> n;
    for(int x = 0; x < n; x++) {
        vector<int> one(100, 0);
        vector<int> two(100, 0);
        vector<int> three(100, 0);
        for(int y = 0; y < 100; y++) {
            cin >> one[y];
        }
        for(int y = 0; y < 100; y++) {
            cin >> two[y];
        }
        for(int y = 0; y < 100; y++) {
            cin >> three[y];
        }
        for(int y = 0; y < 100; y++) {
            if(one[y] == 1) {
                cout << y << " ";
                break;
            }
        }
        for(int y = 0; y < 100; y++) {
            if(two[y] == 1) {
                cout << y << " ";
                break;
            }
        }
        for(int y = 0; y < 100; y++) {
            if(three[y] == 1) {
                cout << y;
                break;
            }
        }
        cout << endl;
    }
}
 */

//Problem A
/*
int main() {
    int t;
    cin >> t;
    for(int x = 0; x < t; x++) {
        int n;
        cin >> n;
        int p, q;
        cin >> p >> q;
        vector<int> cs31(p, 0);
        vector<int> cs32(q, 0);
        for(int y = 0; y < p; y++) {
            cin >> cs31[y];
        }
        for(int y = 0; y < q; y++) {
            cin >> cs32[y];
        }
        int maxx = 0;
        for(int y = 0; y < p; y++) {
            for(int z = 0; z < q; z++) {
                if(cs31[y] + cs32[z] <= n) {
                    maxx = max(maxx, cs31[y] + cs32[z]);
                }
            }
        }
        cout << maxx << endl;
    }
}
*/

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
