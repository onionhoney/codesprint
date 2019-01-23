#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, p, q;
        cin >> n >> p >> q;
        vector<int> v1(p);
        for (int i = 0; i < p; i++)
            cin >> v1[i];
        vector<int> v2(q);
        for (int i = 0; i < q; i++)
            cin >> v2[i];
        
        int ans = 0;
        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v2.size(); j++) {
                if (v1[i] + v2[j] <= n) {
                    ans = max(ans, v1[i] + v2[j]);
                }
            }
        }
        cout << ans << "\n";
    }
}
