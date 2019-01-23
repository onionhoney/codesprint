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
#define rep(i,l,r) for (ll i = (l); i < (r); ++i)
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;


const int N = 20;


void main2() {
    int n; cin >> n;
    vi a( (1 << n) + 1 );
    vvi sum(n + 1, vi(1 + (1 << n)));
    vvi dp(n + 1, vi(1 + (1 << n)));
    rep(i, 1, (1 << n) + 1) {
        char ch; cin >> ch; a[i] = ch;
        if (n % 2 == 0) {
            if (a[i] == 'B') dp[0][i] = 1;
        } else if (a[i] == 'A') dp[0][i] = 1;
        sum[0][i] = sum[0][i - 1] + dp[0][i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= (1 << n) - (1 << i) + 1; j++) {
            ll rb = j + (1 << (i - 1)), lb = j - 1;
            ll canwin = (sum[i - 1][rb] - sum[i - 1][lb]) == 0;
            dp[i][j] = canwin;
            sum[i][j] = dp[i][j] + sum[i][j - 1];
        }
    }
    cout << (dp[n][1] == 0 ? "A" : "B" ) << endl;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    forn(i, t) {
        main2();
    }
}
