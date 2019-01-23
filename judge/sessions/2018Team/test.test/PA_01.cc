#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cassert>
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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; 
    cin >> n; 
    vi a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vvi dp(n + 2, vi(n + 2)), mx(n + 2, vi(n + 2));
    for(int i = 1; i <= n; i++) dp[i][i] = a[i];

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n ; i++) {
            int j = i + l - 1;
            dp[i][j] = dp[i + 1][j] ^ dp[i][j - 1];
        }
    }

    for(int i = 1; i <= n; i++) mx[i][i] = dp[i][i];

    for(int j = 2; j <= n; j++) {
        for (int i = 1; i + j - 1 <= n; i++) {
            mx[i][i + j - 1] = max(max(mx[i + 1][i + j - 1], mx[i][i + j - 2]), dp[i][i + j - 1]);
        }
    }
    
    // preproces
    int q; cin >> q;
    forn(i, q) {
        int l, r; cin >> l >> r; 
        //int po = 0; while ( (1 << (po + 1)) < d ) po++;
        //cout << max(st[l][po], st[r - (1 << po) + 1][po]) << endl;
        cout << mx[l][r] << endl;
    }
}

