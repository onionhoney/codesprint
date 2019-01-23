//
//  Problem_A.cpp
//  LA Code Sprint
//
//  Created by Yuanping Song on 5/20/18.
//  Copyright © 2018 Yuanping Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <cmath>

using namespace std;

int main() {
    int numTests;
    cin >> numTests;
    while (numTests > 0) {
        int numPings, numMates, numTypes; // numPings, numTeammates, numPings.
        cin >> numPings >> numMates >> numTypes;
        vector<int> players;
        vector<int> pings;
        for (int i = 0 ; i < numMates; i++) {
            int temp;
            cin >> temp;
            if (temp != 0) {
                players.push_back(temp);
            }
        }
        for (int i = 0 ; i < numTypes; i++) {
            int temp;
            cin >> temp;
            if (temp != 0) {
                pings.push_back(temp);
            }
        }
        sort(players.rbegin(), players.rend());
        sort(pings.rbegin(), pings.rend());
        
        int playerSum = 0, pingSum = 0;
        for (int x : players) {
            playerSum += x;
        }
        for (int x : players) {
            playerSum += x;
        }
        
        int accumulator = 0;
        bool hasRunOut = false;
        for (int i = 0; i < numPings; i++) {
            if (players.empty() || pings.empty() ) {
                cout << accumulator << " ";
                hasRunOut = true;
                break;
            }
            if (players.front() > pings.front() || (players.front() == pings.front() && playerSum < pingSum)) {
                accumulator += players.front();
                players.front()--;
                pings.back()--;
                sort(players.rbegin(), players.rend());
                sort(pings.rbegin(), pings.rend());
                if (pings.back() == 0) {
                    pings.pop_back();
                }
                if (players.back() == 0) {
                    players.pop_back();
                }
            } else {
                accumulator += pings.front();
                pings.front()--;
                players.back()--;
                sort(players.rbegin(), players.rend());
                sort(pings.rbegin(), pings.rend());
                if (pings.back() == 0) {
                    pings.pop_back();
                }
                if (players.back() == 0) {
                    players.pop_back();
                }
            }
        }
        if (!hasRunOut) {
            cout << accumulator << " ";
        }
        numTests--;
    }
}
