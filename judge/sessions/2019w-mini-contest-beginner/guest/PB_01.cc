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
        string s; cin >> s;
        int n = s.size();
        string ans;
        for (int j = 1; j < n; j+=2) {
            ans += s[j];
        }
        for (int j = (n & 1) ? n - 1 : n - 2; j >= 0; j -= 2) {
            ans += s[j];
        }
        cout << ans << endl;
    }
}
