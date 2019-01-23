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


int last(multiset<int>& x) {
    return *(--x.end());
}

void m2() {
    int n, p ,q, x; cin >> n >> p >> q;
    multiset<int> player, ping;
    forn(i, p) { cin >> x; player.insert(x); }
    forn(i, q) { cin >> x; ping.insert(x); }
    ll ans = 0;
    forn(i, n) {
        if (ping.empty() || player.empty()) break;
        int m1 = last(ping), m2 = last(player);
        if (m1 > m2) {
            ans += m1;
            ping.erase(--ping.end());
            if (m1 -1 > 0) ping.insert(m1 - 1);
            int m2 = *player.begin();
            player.erase(player.begin());
            if (m2 - 1 > 0) {
                player.insert(m2 - 1);
            }
        } else {
            ans += m2;
            player.erase(--player.end());
            if (m2 -1 > 0) player.insert(m2 - 1);
            int m1 = *ping.begin();
            ping.erase(ping.begin());
            if (m1 - 1 > 0) {
                ping.insert(m1 - 1);
            }
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; forn(i, t) m2();
}
