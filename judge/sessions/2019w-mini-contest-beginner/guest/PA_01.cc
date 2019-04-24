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
    int t; cin >> t;
    forn(i, t) {
        int n; cin >> n;
        vvi a(100, vi(100));
        forn(j, n) {
            int k, x1, y1, x2, y2;
            cin >>  k>>x1>>y1>>x2>>y2;
            for (int x = x1; x < x2; x++) 
                for (int y = y1; y < y2; y++)
                    a[x][y] = k;
        }
        int sum = 0;
            for (int x = 0; x < 100; x++) 
                for (int y = 0; y < 100; y++)
                    sum += a[x][y];
        cout << sum << endl;
    }
}
