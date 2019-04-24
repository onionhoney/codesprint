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

int main() {
    ll a[1000];
    ll *b = &a[5];
    for (int i = 0; i <= 5; i++)  {
        a[i] = 1;
    }
    for (int i = 1; i < 500; i++) {
        if (i & 1) {
            b[i] = b[i-1] + b[i-3];
        }
        else {
            b[i] = b[i / 2] + b[i - 2] + b[i- 4];
        }
        ///cout << i << " " << b[i] << endl;
        if (b[i] < 0) break;
    }
    int t; cin >> t;
    forn(i, t) {
        ll x; cin >> x;
        bool flag = 0;
        for (int i = 0; i < 170; i++) {
            if (b[i] == x) {
                cout << i << endl;
                flag = true;
                break;
            }
        }
        if (flag == 0) {
            cout << -1 << endl;
        }
    }
}
