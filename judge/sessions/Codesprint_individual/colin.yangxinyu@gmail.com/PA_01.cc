
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    int numtests;
    cin >> numtests;
    for (int i = 0; i < numtests; i++) {
        int p, n;
        cin >> p >> n;

        int beauty = 0;

        for (int j = 0; j < p; j++) {
            int bi, ni;
            cin >> bi >> ni;
            if (n <= 0)
                continue;

            beauty += min(ni, n) * bi;
            n -= min(ni, n);
        }

        cout << beauty << endl;
    }

    return 0;
}
