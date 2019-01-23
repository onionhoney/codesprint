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


void m2() {
    int n, k; cin >> n >> k;
    vector<pii> v;

    forn(i, n) {
        ll x;
        cin >> x;
        v.PB({x, i});
    }
    const ll ninf = -1000000000000LL;
    vvi dp(n, vi(k + 1, ninf));
    sort(all(v));// reverse(all(a));

    dp[0][1] = v[0].first;
    forn(i, n) dp[i][0] = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            ll val = v[i].first, idx = v[i].second;
            ll avail = i - 1;
            while (avail >= 0 && abs(v[avail].second - idx) == 1) avail--;
            //cerr << i << " " << j << " val " << v[i].first << " idx " << v[i].second << " avail " << avail << endl;
            if (avail < 0) dp[i][j] = (j == 1) ? val : dp[i-1][j]; else
            dp[i][j] = max(dp[avail][j - 1] + val, dp[i - 1][j]); 
            //cerr << i << " " << j << " " << dp[i][j] << " " << dp[i-1][j] << endl;
        }
    }
    cout << dp[n-1][k] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; forn(i, t) m2();
}
