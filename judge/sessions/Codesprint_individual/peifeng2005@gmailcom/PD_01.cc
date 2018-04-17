#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<pair<int, int>> instructs;
    vector<char> letters;
    for(int i = 0; i < n; i++){
        int s, e;
        char c;
        cin >> s >> e >> c;
        instructs.emplace_back(s, e);
        letters.push_back(c);
    }
    vector<int> arr(4);
    vector<char> ans(4);
    for(int i = 0; i < 4; i++){
        ans[i] = 'a';
    }
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    for(int i = 0; i < n; i++){
        auto p = instructs[i];
        for(int j = 0; j < 4; j++){
            if(p.first <= arr[j] && p.second >= arr[j])
                ans[j] = letters[i];
        }
    }
    for(int i = 0; i < 3; i++){
        cout << ans[i] << " ";
    }
    cout << ans[3] << endl;
}