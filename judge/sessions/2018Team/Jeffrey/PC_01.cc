#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <cmath>
#define PB push_back
#define MP make_pair
#define sz(v) (ll((v).size()))
#define forn(i,n) for(ll i = 0; i < (n); ++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;


int last(multiset<int>& x) {
    return *(--x.end());
}

void m2() {
    int n, s; cin >> n >> s; 
    vector<double> v(n);
    vector<int> b(n);
    forn(i, n) cin >> v[i]; forn(i, n) cin >> b[i];

    s = min(n, s);
    vector<double> dp(s + 10);
    dp[s - 1] = 1 - v[s - 1];

    for (int i = s - 2;i >= 0; i--) {
        dp[i] = (1 - v[i]) * (1 + dp[i + 1]) + v[i] * (dp[i + b[i] + 1]);
    }

    
    cout << floor(dp[0]) << endl;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; forn(i, t) m2();
}
