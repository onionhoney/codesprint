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

void m2() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int run = 0; int dir = 0;
    int sum = 0;
    forn(i, sz(s)) {
        if (s[i] == 'R') {
            if (dir == -1) run++;
            else { 
                if (run >= k) sum += dir * (run / k);
                run = 1; dir = -1;
            }
        }
        else if (s[i] == 'L') {
            if (dir == 1) run++;
            else {
                if (run >= k) sum += dir * (run / k);
                run = 1; dir = 1; 
            }
        } else {
            if (run >= k) sum += dir * (run / k);
            run = 1; dir = 0;
        }
    }
    if (run >= k) sum += dir * (run/ k);
    cout << sum << endl;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; forn(i, t) m2();
}
