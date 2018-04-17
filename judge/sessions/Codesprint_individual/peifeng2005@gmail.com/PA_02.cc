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
    int t, p, n;
    cin >> t;
    for(int j = 0; j < t; j++){
        int beauty = 0;
        cin >> p >> n;
        for (int i = 0; i < p; i++){
            int bi, ni;
            cin >> bi >> ni;
            if(n == 0)
                continue;
            int amount = min(ni, n);
            n -= amount;
            beauty += amount * bi;
        }
        cout << beauty << endl;
    }
}