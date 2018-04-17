#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;  // # of testcase;
    cin >> t;
    vector<int> results;
    for (int i = 0; i < t; i++) {
        int m, n, linenum;
        cin >> m >> n;
        cin >> linenum;
        int x1, y1, x2, y2;
        int horlines = 0, verlines = 0;
        for (int j = 0; j < linenum; j++) {
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 == x2)
                verlines++;
            else
                horlines++;
        }
        int ans = (horlines + 1) * (verlines + 1);
        results.push_back(ans);
    }
    
    for (int i = 0; i < t; i++) {
        cout << results[i] << endl;
    }
    
}
