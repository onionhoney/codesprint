// =========== START OF TEMPLATE ==============
#define TESTING

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <sstream>
#include <cmath>
#include <stack>
#include <string>
#define PB push_back
#define MP make_pair
#define sz(v) (ll((v).size()))
#define forn(i,n) for(ll i = 0; i < (n); ++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(), (v).end()
#define min(a,b) (a<b)?a:b
#define max(a,b) (a>b)?a:b
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
//int INF = 1000000005;
//long long INFF = 1000000000000000005ll;
//double PI = acos(-1);

//#ifdef TESTING
//#define DEBUG fprintf(stderr,"====TESTING====\n")
//#define what_is(x) cerr << #x << " is " << x << endl
//#define debug(...) fprintf(stderr, __VA_ARGS__)
//#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
//vector<string> split(const string& s, char c) {
//    vector<string> v;
//    stringstream ss(s);
//    string x;
//    while (getline(ss, x, c))
//        v.emplace_back(x);
//    return move(v);
//}
//void err(vector<string>::iterator it) {}
//template<typename T, typename... Args>
//void err(vector<string>::iterator it, T a, Args... args) {
//    cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
//    err(++it, args...);
//}
//#else
//#define DEBUG
//#define what_is(x)
//#define debug(...)
//#endif

//inline void CLOSE () {
//    fclose(stdin);
//    fclose(stdout);
//}

// =========== END OF TEMPLATE ==============

inline void OPEN (string s) {
    freopen ((s + ".in").c_str (), "r", stdin);
    freopen ((s + ".out").c_str (), "w", stdout);
}

ll funcC(ll x) {
    ll ans = x*(x-1)/2;
    return ans;
}

#if 1
int main()
{
    string FNAME = "/home/haoyu/CompetitiveProgrammingProblems/ICPC_Notes/A";
    OPEN(FNAME);

    int c;
    cin >> c;

    for (int l = 0; l < c; ++l) {
        int n,p1,q1;
        long long temp;
        cin >> n >> p1 >> q1;
        multiset<long long> a;
        multiset<long long> b;
        for (int i = 0; i < p1; ++i) {
            cin >> temp;
            a.insert(temp);
        }
        for (int i = 0; i < q1; ++i) {
            cin >> temp;
            b.insert(temp);
        }

        long long unhappiness = 0;
        for (int i = 0; i < n; ++i) {
            if (a.empty() || b.empty()) break;

            // Get last elements
            multiset<long long>::iterator p = a.end();
            --p;
            multiset<long long>::iterator q = b.end();
            --q;
            multiset<long long>::iterator r;
            // Check if player value is greater
            if (*p > *q || (*p == *q && *b.begin() < *a.begin())) {
                unhappiness += *p;
                if (*p - 1 > 0) a.insert(*p - 1);
                a.erase(p);
                r = b.begin();
                if (*r - 1 > 0) b.insert(*r - 1);
                b.erase(r);
            } else {
                unhappiness += *q;
                if (*q - 1 > 0) b.insert(*q - 1);
                b.erase(q);
                r = a.begin();
                if (*r - 1 > 0) a.insert(*r - 1);
                a.erase(r);
            }
        }

        cout << unhappiness << "\n";

        /*if (l != c - 1) cout << unhappiness << " ";
        else cout << unhappiness;*/
    }
}


#else if 1

int main() {
    string FNAME = "/home/haoyu/CompetitiveProgrammingProblems/ICPC_Notes/A";
    OPEN(FNAME);

    // faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

}

#endif
