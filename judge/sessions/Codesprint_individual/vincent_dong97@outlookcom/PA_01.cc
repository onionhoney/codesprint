#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int t;  // # of testcase
    struct test {
        int p;  // # of types
        int n;  // # of total flowers
        vector<int> beauty;
        vector<int> max;
    };
    cin >> t;
    vector<test> testcase;
    
    for (int i = 0; i < t; i++) {
        test cur;
        cin >> cur.p;
        cin >> cur.n;
        for (int j = 0; j < cur.p; j++) {
            int b, maximum;
            cin >> b;
            cin >> maximum;
            cur.beauty.push_back(b);
            cur.max.push_back(maximum);
        }
        testcase.push_back(cur);
    }
    
    for (int i = 0; i < t; i++) {
        test tc = testcase[i];
        int typenum = tc.p;
        int maxflowers = tc.n;
        int curflowers = 0, curbeauty = 0;
        for (int j = 0; j < typenum; j++) {
            if ( curflowers + tc.max[j] <= maxflowers ) {
                curflowers += tc.max[j];
                curbeauty += tc.beauty[j] * tc.max[j];
            }
            else {
                curbeauty += tc.beauty[j] * (maxflowers - curflowers);
                break;
            }
        }
        cout << curbeauty << endl;
    }
}
