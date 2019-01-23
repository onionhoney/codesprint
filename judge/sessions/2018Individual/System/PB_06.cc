#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int a[1000];
    for (int z = 0; z < n; z++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> a[j];
                if (a[j] == 1) {
                    cout << j << endl;
                }
            }
        }
    }
}
