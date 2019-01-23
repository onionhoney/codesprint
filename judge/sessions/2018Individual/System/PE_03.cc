//
//  main.cpp
//  Fast Simple Banach-Mazur
//
//  Created by Justin Li on 5/14/18.
//  Copyright © 2018 Justin Li. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {
    //char board[1024];
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
        //cout << "starting" << endl;
        for (int l = 1; l <= n; l++) { // choosing subarray of length 2^l
            for (int j = 0; j < N-pow(2, l)+1; j++) { // subarray chosen starting from jth index
                if ((n+l)%2 == 1) { // Alice chooses this length subarray, Bob will pick the next subarray from here
                    dp[l][j] = 'A'; // If all possibilities lead to Alice winning, then Alice wins
                    for (int k = 0; k < pow(2, l-1)+1; k++) {
                        if (dp[l-1][j+k] == 'B') { // since Bob has the power to choose the next one, if he can choose one where he wins, then Alice choosing this spot results in Bob winning
                            dp[l][j] = 'B';
                            break;
                        }
                    }
                } else { // Bob chooses the subarray
                    dp[l][j] = 'B';
                    for (int k = 0; k < pow(2, l-1)+1; k++) {
                        if (dp[l-1][j+k] == 'A') {
                            dp[l][j] = 'A';
                            break;
                        }
                    }
                }
            }
        }
        
        cout << dp[n][0] << endl;
        /*cout << endl;
        for (int l = 0; l <= n; l++) {
            for (int j = 0; j < N-pow(2, l)+1; j++) {
                cout << dp[l][j] << " ";
            }
            cout << endl;
        }
        cout << endl;*/
    }
}
