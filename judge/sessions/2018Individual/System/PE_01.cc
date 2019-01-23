#include <iostream>
#include <math.h>

using namespace std;

int max (int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main(int argc, const char * argv[]) {
    char dp[18][131072];
    int t;
    cin >> t;
    int n, N;
    for (int z = 0; z < t; z++) {
        cin >> n;
        N = pow(2, n);
        for (int i = 0; i < N; i++) {
            cin >> dp[0][i];
        }
        for (int l = 1; l <= n; l++) { // choosing subarray of length 2^l
            if ((n+l)%2 == 1) {
                for (int j = 0; j < N-pow(2, l)+1; j++) {
                    dp[l][j] = 'A';
                }
                //look at row above, if any are 'B', then you know that down and to the left is 'B'
                int nextpossiblechange = 0;
                for (int k = 0; k < N-pow(2, l-1)+1; k++) {
                    if (dp[l-1][k] == 'B') {
                        for (int m = max(nextpossiblechange, k-(pow(2, l-1))); m <= k; m++) {
                            dp[l][m] = 'B';
                        }
                        nextpossiblechange = k+1;
                    }
                }
            } else {
                for (int j = 0; j < N-pow(2, l)+1; j++) {
                    dp[l][j] = 'B';
                }
                //look at row above, if any are 'A', then you know that down and to the left is 'A'
                int nextpossiblechange = 0;
                for (int k = 0; k < N-pow(2, l-1)+1; k++) {
                    if (dp[l-1][k] == 'A') {
                        for (int m = max(nextpossiblechange, k-(pow(2, l-1))); m <= k; m++) {
                            dp[l][m] = 'A';
                        }
                        nextpossiblechange = k+1;
                    }
                }
            }
        }
        cout << dp[n][0] << endl;
    }
}
