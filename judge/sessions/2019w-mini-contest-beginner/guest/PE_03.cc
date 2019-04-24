#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <stack>
#define PB push_back
#define MP make_pair
#define forn(i,n) for(ll i = 0; i < (n); ++i)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;

ll dp[100][100];
ll f(int buy, int sell) {
    if (buy > sell) return 0;
    if (buy < 0 || sell < 0) return 0;
    if (buy == 0 && sell == 0) return 1;
    ll sum = 0;
    sum += f(buy - 1 , sell);
    sum += f(buy, sell - 1);
    //cout << buy <<"," << sell << " " << sum << endl;
    return sum;
}
int styp(char s) {
    switch (s) {
        case '(': return 1;
        case ')': return -1;
        case '{': return 2;
        case '}': return -2;
        case '[': return 3;
        case ']': return -3;
        default: return 0;
    }
}
bool ispair(string s) {
    stack<int> st;
    for (int j = 0; j < s.size(); j++) {
        int rc = styp(s[j]);
        if (rc) {
            if (rc > 0) {
                st.push(rc);
            } else {
                if (st.empty() || st.top() + rc != 0) {
                    return false;
                }
                st.pop();
            }
        }
    }
    return (st.empty());
}
int main() {
    /*
    int ans[28];
    for (int i = 1; i <= 26; i++) {
        ans[i] = f(i, i);
        cerr << i << " " << ans[i] << endl;
    }
    */
    int t; cin >> t;
    forn(i, t) {
        string s; cin >> s;
        if (!ispair(s)) cout << "false"; else cout << "true";
         cout << endl;
    }
}
