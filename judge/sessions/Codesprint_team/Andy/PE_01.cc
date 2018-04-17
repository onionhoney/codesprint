#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <cmath>
#include <bitset>
#include <climits>
#include <iomanip>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstring>

using namespace std;

#define ll long long
#define N (ll)(1e6+5)
#define INF (ll)(1e18+3)
#define EPS (1e-9)
#define PI (3.14159265358979323846)
#define ld double
#define MOD (ll)(1e9+7)

void solve() {
    ll r;
    cin >> r;
    
    vector<pair<double,ll> > v;
    
    ll ans = 0;
    for (ll i = -r; i <= r; i++) {
        ll x = sqrt(r*r-i*i);
        ans += 2*x+1;
    }
    for (ll i = -r; i <= r; i++) {
        ll x = sqrt(r*r-i*i);
        double sub = sqrt(r*r-i*i)-x;
        double add = x+1-sqrt(r*r-i*i);
        v.push_back({sub,1});
        v.push_back({add,-1});
    }
    sort(v.begin(), v.end());
    
    ll res = ans;
    for (ll i = 0; i < v.size(); i++) {
        ans += -1*(v[i].second);
        res = max(res, ans);
    }
    
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
        solve();
}