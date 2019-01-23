#if 1

// =========== START OF TEMPLATE ==============
#define TESTING

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
//#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <sstream>
#include <cmath>
#include <stack>
#define PB push_back
#define MP make_pair
#define sz(v) (ll((v).size()))
#define forn(i,n) for(ll i = 0; i < (n); ++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(), (v).end()
#define min(a,b) (a<b)?a:b
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

int main()
{
//    string FNAME = "A";
//    OPEN(FNAME);

    // faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    unsigned int TC, n, l, k, a, b;
    ll x;
    scanf("%d", &TC);
    forn(i, TC) {
        scanf("%d %d %d", &n, &l, &k);
        vector<bool>visited(n,0);
        map<unsigned int, vector<int> >adj;

        forn(j, n) {
            adj[j] = vector<int>();
        }

        forn(j, l) {
            scanf("%d %d", &a, &b);
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int>cc;
        stack<int>st;
        forn(j, n) {
            if (!visited[j]) {
                int count = 0;
                st.push(j);
                while (!st.empty()) {
                    x = st.top(); st.pop();
                    count++;
                    visited[x] = true;
                    forv(n, adj[x]) {
                        if (!visited[adj[x][n]])
                            st.push(adj[x][n]);
                    }
                }
                cc.push_back(count);
            }
        }
        sort(cc.begin(), cc.end());
        k = min(cc.size()-1, k);

        int largest = 0;
        forn(j, k+1) {
            largest += cc[j];
        }

//        forv(j, cc) {
//            printf("%d ", cc[j]);
//        }

        ll total = funcC(largest);
        for(unsigned int j = k+1; j < cc.size(); j++)
            total += funcC(cc[j]);

        printf("%lld\n", total);
    }

}


#else if 0

{
int TC, jumps, p, q, el;
vector<int> a;
vector<int> b;
scanf("%d", &TC);
forn(i, TC) {
    scanf("%d", jumps);
    scanf("%d%d", p, q);
    forn(j, p) {
        scanf("%d", el);
        a.push_back(el);
    }
    forn(k, q) {
        scanf("%d", el);
        b.push_back(el);
    }

} }

#endif
