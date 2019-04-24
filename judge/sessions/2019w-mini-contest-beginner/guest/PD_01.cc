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

ll f(int buy, int sell) {
    if (buy > sell) return 0;
    if (buy < 0 || sell < 0) return 0;
    if (buy == 0 && sell == 0) return 1;
    ll sum = 0;
    sum +=  f(buy - 1 , sell);
    sum +=  f(buy, sell - 1);
    //cout << buy <<"," << sell << " " << sum << endl;
    return sum;
}
int main() {
    int ans[14];
    for (int i = 1; i <= 13; i++) {
        ans[i] = f(i, i);
        cout << i << " " << ans[i] << endl;
    }
    int t; cin >> t;
    forn(i, t) {
        ll x; cin >> x;
        cout << ans[x / 2] << endl;
    }
}
