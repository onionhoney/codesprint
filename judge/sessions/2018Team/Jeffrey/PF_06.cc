#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <cmath>
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

struct tile {
    int v, x, y;
    tile(int v, int x, int y) : v(v), x(x), y(y) {}
    tile() : v(0), x(0), y(0) {}
    string desc() {
        stringstream ds;
        ds << v << " = (" << x << "," << y << ") ";
        return ds.str();
    }
    bool operator> (const tile& other) const {
        return v > other.v ||
            (v == other.v && x > other.x) ||
            (v == other.v && x == other.x && y > other.y);
    }
    bool operator== (const tile& other) const {
        return v == other.v &&
            x == other.x &&
            y == other.y;
    }
};

typedef set<tile, greater<tile> > tileset;
int n;
vvi dp, val;
int get(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) return 0;
    return dp[x][y];
}

int score(int i, int j) {
    int v = 0;
    if (i < 0 || i >= n || j < 0 || j >= i * 2 + 3) return 0;
    if ( j % 2 == 0) {
        int t = j / 2 - 1;
        v = get(i, t) + get(i, t + 1) + get(i - 1, t);
    } else {
        int t = j / 2 - 1;
        v = get(i, t + 1) + get(i - 1, t) + get(i - 1, t + 1);
    }
    return v;
}
vector<tile> neighbors(const tile& t) {
    vector<tile> ans;
    int incr = (t.y % 2 == 0) ? 1 : -1;
    ans.PB({score(t.x, t.y - 1), t.x, t.y - 1});
    ans.PB({score(t.x, t.y + 1), t.x, t.y + 1});
    ans.PB({score(t.x + incr, t.y + incr), t.x + incr, t.y + incr});
    return ans;
}

bool conflict(const tile& t1, const tile& t2) {
    if (t1.x == t2.x) return abs(t1.y - t2.y) <= 1;
    int incr = (t1.y % 2 == 0) ? 1 : -1;
    return (t1.x + incr == t2.x && t1.y + incr == t2.y);
}

void expand(tileset& tiles) {
    tileset newtiles;
    for (auto t : tiles) {
        for (auto n : neighbors(t)) 
            newtiles.insert(n);
    }
    for (auto t : newtiles) 
        if (t.v > 0) tiles.insert(t);
}

tile sol2[4];
tile sol1[4];
tile currt;

int play2(tileset& tiles) {
    vector<tile> l(all(tiles));
    int maxscore = -1000000;
    for (auto t1 : l) {
        //vector<tile> nt1 = neighbors(t1);
        for (auto t2 : l) {
            if (conflict(t1, t2)) continue;

            int score = t1.v + t2.v;
            tile toppo(0, 0, 0);
            for (auto t3: l) {
                if (conflict(t1, t3) || conflict(t2, t3)) continue;
                toppo = t3;
                score -= t3.v;
                break;
            }
            if (score > maxscore ) {
                maxscore = score;
                //sol2[1] = t1;
                //sol2[2] = t2;
                //sol2[3] = toppo;

                //cout << " under " << currt.desc() << ":\n";
                //forn(i,3) cout << sol2[i+1].desc() << endl;
            }
            //for (auto n : nt) tiles.insert(n);
            
        }
    }
    return maxscore;
}
int play1(tileset& tiles) {
    vector<tile> l(all(tiles));
    int maxscore = -1000000;
    for (auto t : l) {
        currt = t;
        tiles.erase(t);
        for (auto n : neighbors(t)) tiles.erase(n);
        int score = t.v - play2(tiles);
        
        if (score > maxscore) {
            maxscore = score;
            forn(i, 4) sol1[i] = sol2[i];
            sol1[0] = t;
        }

        tiles.insert(t);
        for (auto n : neighbors(t)) tiles.insert(n);
    }
    //cout << "solution" << endl;
    //forn(i, 4) cout << sol1[i].desc() << endl;
    return maxscore;
}
char hex(int x) {
    if (x < 10) return '0' + x;
    else return 'a' + (x - 10);
}

void main2() {
    cin >> n;
    vector<tile> tiles;
    //dp = vvi(n, vi(n));

    dp.clear(); dp.resize(n);
    forv(i, dp) { dp[i].clear(); dp[i].resize(n); }

    val.clear(); val.resize(n + 2);
    forv(i, val) { val[i].clear(); val[i].resize(n * 2 + 10); }
    //for (vvi(n + 2, vi(n * 2 + 10));

    int rawtoscore[13] = {
        0, 0, 1, 2, 3, 4, 5, 0, 5, 4, 3, 2, 1
    };
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < i + 1; j++)  {
            int x;
            cin >> x; 
            dp[i][j] = rawtoscore[x];
        }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < i * 2 + 3; j++) {
            // upper triangle
            int v = score(i, j);
            //val[i][j] = v;
            if (v == 0) continue;
            tiles.PB({v, i, j});
        }
    }

    /*
    for(int i = 0;i <= n; i++) {
        for (int j = 0; j < (n - i) * 2; j++) cout << " ";
        for (int j = 0; j < i * 2 + 3; j++) {
            //cout.width(3);
            cout << hex(val[i][j]) << " ";
        }
        cout << endl;
        for (int j = 0; j < (n - i) * 2; j++) cout << " ";
        for (int j = 0; j < i * 2 + 3; j++) {
            //cout.width(3);
            if (j % 2 == 0)
            cout << "| "; else cout << "  ";
        }
        cout << endl;
    }
    */

    sort(all(tiles), greater<tile>());
    // all tiles must be placed within distance 2 from the top 10 tiles. 
    tileset rel;
    for (int i = 0; i < min(13LL, sz(tiles)); i++) {
        rel.insert(tiles[i]);
    }
    for (int i = 0; i < 2; i++) expand(rel);
    // for (auto tile : rel) { cerr << tile.desc() << endl; }

    int result = play1(rel);
    assert(result >= -100);
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    forn(i, tc) {
        main2();
    }

}
