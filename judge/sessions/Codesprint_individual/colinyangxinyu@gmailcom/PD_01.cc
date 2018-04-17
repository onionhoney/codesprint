
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int beg, end;
    char c;

    node(int b, int e, char c)
        : beg(b), end(e), c(c) {}
};


int main()
{
    int n;
    cin >> n;

    // vector<node> str;
    // str.push_back(node(0, 999999, 'a'));
    char str[1000000];
    memset(str, 'a', 1000000);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        char c;
        cin >> c;
        memset(str+l, c, r-l+1);
    }
    int i0, i1, i2, i3;
    cin >> i0 >> i1 >> i2 >> i3;
    cout << str[i0] << ' ' << str[i1] << ' ' << str[i2] << ' ' << str[i3] << ' ' << endl;

    return 0;
}
