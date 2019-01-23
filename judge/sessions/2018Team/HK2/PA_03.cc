//
//  main.cpp
//  codesprint
//
//  Created by Kyle Hess on 5/20/18.
//  Copyright © 2018 Kyle Hess. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cmath>
using namespace std;



int main() {
    int t;
    cin >> t;
    
    for (int l = 0; l < t; ++l) {
        int n, k;
        cin >> n >> k;
        cin.ignore(1000, '\n');
        string shots;
        getline(cin, shots);
        
        int counter = 0;
        int calibration = 0;
        for (int i = 0; i < shots.size(); ++i) {
            if (shots[i] == 'H') {
                counter = 0;
            } else if (shots[i] == 'L') {
                if (counter >= 0) {
                    counter = -1;
                } else {
                    --counter;
                    if (counter <= -k) {
                        counter = 0;
                        ++calibration;
                    }
                }
            } else if (shots[i] == 'R') {
                if (counter <= 0) {
                    counter = 1;
                } else {
                    ++counter;
                    if (counter >= k) {
                        counter = 0;
                        --calibration;
                    }
                }
            }
        }
        
        cout << calibration << endl;
    }
}




/*int main() {
    int t;
    cin >> t;
    for (int l = 0; l < t; ++l) {
        int k,n;
        cin >> n >> k;
        vector<int> popul;
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            popul.push_back(temp);
        }
        
        
    }
}*/



/*int isInside(int a, int b, int c, int d) {
    return a <= c && d <= b;
}

int main() {
    int t;
    cin >> t;
    
    for (int l = 0; l < t; ++l) {
        int n;
        cin >> n;
        
        // If n = 1, then Alice is last to play
        int player = (n + 1) % 2;
        
        vector<int> whoWins;
        vector<int> theArray;
        // Fill the vector
        for (int i = 0; i < pow(2,n); ++i) {
            char temp;
            cin >> temp;
            
            if (temp == 'A') {whoWins.push_back(0); theArray.push_back(0);}
            else {whoWins.push_back(1); theArray.push_back(1);}
        }
        
        for (int i = 1; i <= n; ++i) {
            vector<int> newWhoWins;
            
            
            int numOtherWins = 0;
            for (int j = 0; j <= pow(2,i-1); ++j) {
                if (whoWins[j] != player) ++numOtherWins;
            }
            if (numOtherWins > 0) newWhoWins.push_back(!player);
            else newWhoWins.push_back(player);
            
            for (int j = 0; j < pow(2,n)-pow(2,i); ++j) {
                numOtherWins += (player != whoWins[j+pow(2,i-1)+1]) - (player != whoWins[j]);
                if (numOtherWins > 0) newWhoWins.push_back(!player);
                else newWhoWins.push_back(player);
            }
            
            /*for (int j = 0; j <= pow(2,n) - pow(2,i); ++j) {
                // Check if interval starting at j will win for player
                int whoWinsHere = !player;
                for (int k = j; k < j + pow(2,i-1); ++k) {
                    if (whoWins[k] == player) whoWinsHere = player;
                }
                newWhoWins.push_back(whoWinsHere);
            }
            
            whoWins = newWhoWins;
            player ^= 1;
        }
        
        
        if (whoWins[0]) {
            cout << "B" << "\n";
        } else {
            cout << "A" << "\n";
        }
    }
}

*/









/*
int main() {
 
}
 */


/*
int main() {
    
    
}*/






/*
int main() {
    int n;
    cin >> n;
    
    for (int l = 0; l < n; ++l) {
        
        vector<int> a;
        vector<int> b;
        vector<int> c;
        for (int i = 0; i < 100; ++i) {
            int temp;
            cin >> temp;
            if (temp == 1) cout << i;
        }
        cout << " ";
        for (int i = 0; i < 100; ++i) {
            int temp;
            cin >> temp;
            if (temp == 1) cout << i;
        }
        cout << " ";
        for (int i = 0; i < 100; ++i) {
            int temp;
            cin >> temp;
            if (temp == 1) cout << i;
        }
        
        if (l != n - 1) cout << "\n";
    }
}
*/




/*

int main() {
    int t;
    cin >> t;
    
    for (int k = 0; k < t; ++k) {
    
    int n;
    cin >> n;
    int p,q;
    cin >> p >> q;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < p; ++i) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < q; ++i) {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    
    vector<int> sums;
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < q; ++j) {
            sums.push_back(a[i]+b[j]);
        }
    }
    
    int maxstud = 0;
    for (int i = 0; i < p*q; ++i) {
        if (sums[i] <= n) maxstud = max(sums[i], maxstud);
    }
    
    cout << maxstud;
    cout << "\n";
        
    }
    
}
*/













































