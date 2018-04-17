
#include <iostream>
#include <algorithm>

using namespace std;


long long cache[2000001];
bool used      [2000001] = {0};

long long section(int i) {
    if (i <= 0) return 0 == i;
    if (used[i])
        return cache[i];

    used[i] = true;
    long long ways = (section(i-1) + section(i-2) + section(i-3)) % 10007;
    cache[i] = ways;
    // cout << i << ' ' << ways << endl;
    return ways;
}

int main()
{
    int numtests;
    cin >> numtests;

    for (int i = 0; i < 1000000; i++) {
        section(i);
    }

    for (int i = 0; i < numtests; i++) {
        int n;
        cin >> n;

        long long total = 1;

        for (int j = 0; j < n; j++) {
            int s;
            cin >> s;

            total = total*section(s) % 10007;
        }

        cout << total % 10007 << endl;
    }

    return 0;
}
