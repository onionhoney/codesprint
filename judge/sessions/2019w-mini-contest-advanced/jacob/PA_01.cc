#include <iostream>

using namespace std;

int main () {
    int canvas[100][100];

    int N;
    cin >> N;

    for (int testcase = 0; testcase < N; testcase++) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                canvas[i][j] = 0;
            }
        }

        int n;
        cin >> n;
        for (int r = 0; r < n; r++) {
            int a, b, c, d, e;
            cin >> a >> b >> c >> d >> e;
            for (int i = b; i < d; i++) {
                for (int j = c; j < e; j++) {
                    canvas[i][j] = a;
                }
            }
        }
        int total = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                total += canvas[i][j];
            }
        }

        cout << total << endl;

    }


    return 0;
}