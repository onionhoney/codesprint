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

vi p;

int find(int x) {
    return (x== p[x]) ? x : (x = find(p[x]));
}
void unite(int x, int y) {
    int px = find(x), py = find(y);
    p[px] = py;
}

void main2() {
    ll w, h, n, R;
    cin >> w >> h >> R;
    cin >> n;
    vi x(n+2), y(n+2), r(n+2);
    p.resize(n + 2);

    forn(i, n) {
        cin >> x[i] >> y[i] >> r[i];
    }
    int LWALL = n, RWALL = n + 1;

    //forn(leave, n) {
    forn(i, n+2) p[i] = i;
    forn(i, n) {
        if (x[i] - r[i] < R + R) {
            unite(LWALL, i);
        }
        if (w - (x[i] + r[i]) < R + R) {
            unite(RWALL, i);
        }
    }
    forn(i, n) {
        forn(j, i) {
            ll dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (dist < (r[i] + r[j] + R + R) * (r[i] + r[j] + R + R) ) {
                unite(i, j);
            }
        }
    }
    if (find(LWALL) != find(RWALL)) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
    // model each point as what
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    forn(i, t) main2();
}
