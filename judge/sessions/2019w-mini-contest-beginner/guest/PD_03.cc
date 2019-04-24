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
int main() {
    /*
    int ans[28];
    for (int i = 1; i <= 26; i++) {
        ans[i] = f(i, i);
        cerr << i << " " << ans[i] << endl;
    }
    */
    dp[0][0] = 1;
    ll N = 27;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (i + j == 0) continue;
            if (i > 0) 
            dp[i][j] = dp[i - 1][j];
            if (j > i) {
                dp[i][j] += dp[i][j-1];
            }
        }
    }
    int t; cin >> t;
    forn(i, t) {
        ll x; cin >> x;
        x *= 2;
        cout << dp[x / 2][x/2] << endl;
    }

}
