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
        vector<int> v1(100);
        for (int i = 0; i < v1.size(); i++)
            cin >> v1[i];
        vector<int> v2(100);
        for (int i = 0; i < v2.size(); i++)
            cin >> v2[i];
        vector<int> v3(100);
        for (int i = 0; i < v3.size(); i++)
            cin >> v3[i];
        
        long ans1 = find(v1.begin(), v1.end(), 1) - v1.begin();
        long ans2 = find(v2.begin(), v2.end(), 1) - v2.begin();
        long ans3 = find(v3.begin(), v3.end(), 1) - v3.begin();
        
        cout << ans1 << " " << ans2 << " " << ans3 << "\n";
    }
}
