//
//  main.cpp
//  ProblemC
//
//  Created by Edward Chu on 28/1/2017.
//  Copyright © 2017 Puffins. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int numtestCases;
    cin >> numtestCases;
    for (int test = 0; test < numtestCases; test++) {
        
        int dist, numLights, limit;
        cin >> dist;
        cin >> numLights;
        cin >> limit;
        
        int* locs = new int[numLights];
        
        int* periods= new int[numLights];
        for (int j = 0; j < numLights; j++) {
            cin >> locs[j];
            cin >> periods[j];
        }
        
        
        
        for(int speed = limit; speed > 0; speed--){
            bool flag = false;
            for(int i = 0; i < numLights; i++){
                if(((locs[i]/speed) / periods[i]) % 2 == 1 ){
                    flag = true;
                    break;
                }
            }
            
            if(flag)
                continue;
            
            cout << speed << endl;
            
            goto start;
        }
        
        cout << -1 << endl;
        
    start:;
        /*
        int min = 100000, per = 0; // organizes by distance
        for (int j = 0; j < num; j++) {
            min = 100000;
            for (int k = j; k < num; k++) {
                if (templocs[k] < min) {
                    min = templocs[k];
                    per = temppers[k];
                }
            }
            locs[j] = min;
            pers[j] = per;
         
        }
         */
    }
}
