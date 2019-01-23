#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    int n, p, q;
    int a[1000];
    int b[1000];
    for (int z = 0; z < t; z++) {
        cin >> n >> p >> q;
        for (int i = 0; i < p; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < q; i++) {
            cin >> b[i];
        }
        int max = -221;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < q; j++) {
                if ((a[i] + b[j] <= n) && (a[i] + b[j] > max)) {
                    max = a[i] + b[j];
                }
            }
        }
        cout << max << endl;
    }
}
