#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>

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

struct huffman {
    huffman* l = NULL;
    huffman* r = NULL;
    char content;
    int cost;
    bool operator>(huffman& other) const 
    {
        if (cost > other.cost) return true;
        if (cost == other.cost && l > other.l) return true;
        if (cost == other.cost && l == other.l && r > other.r) return true;
        if (cost == other.cost && l == other.l && r == other.r && content > other.content) return true;
        return false;
    }
    huffman(char content, int cost) {
        this->content = content;
        this->cost = cost;
    }
    huffman(huffman* left, huffman* right) {
        assert(left != NULL && right != NULL);
        l = left;
        r = right;
        cost = left->cost + right->cost;
    }
    int getcost(int currdepth) {
        if (l == NULL && r == NULL) {
            //cout << "human tree at " << (char)content << " is " << " length " << currdepth << " freq " << cost << " total " << 
            //    cost * currdepth << endl;
            return cost * currdepth;
        }
        assert(l != NULL & r != NULL);
        return l->getcost(currdepth + 1) + r->getcost(currdepth + 1);
    }
};

struct cmp 
{
    bool operator () (huffman* a, huffman* b) {
        if (a == NULL) return true;
        if (b == NULL) return true;
        return *a > *b;
    }
};


int cost(string s) {
    map<char, int> cnt;
    for (int i = 0; i < sz(s); i++)  {
        cnt[s[i]]++;
    }
    
    priority_queue<huffman*, vector<huffman*>, cmp > pq;
    // put all in 
    for (auto p : cnt) {
        pq.push(new huffman(p.first , p.second));
    }
    if (sz(pq) == 1) {
        return sz(s);
    }
    while (sz(pq) > 1) {
        huffman* p1 = pq.top(); pq.pop();
        huffman* p2 = pq.top(); pq.pop();
        huffman* pnew = new huffman(p1, p2);
        pq.push(pnew);
    }
    // observe this, by traversing 
    return pq.top()->getcost(0);
}

void m2() {
    int n, c; cin >> n >> c;
    cin.ignore(100, '\n');
    string s;
    cin >> s;
    //cout << " cost of assembling whole tree is " << cost(s) << endl;
    int ans = 1;
    for (int i = sz(s); i >= 1; i--) {
        bool flag = false;
        for (int j = 0; j + i <= sz(s); j++) {
            if (cost(s.substr(j, i)) <= c) {
                flag = true;
                ans = i; break;
            }
        }
        if (flag) break;
    }
    cout << ans << endl;
}


int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) m2();
}
