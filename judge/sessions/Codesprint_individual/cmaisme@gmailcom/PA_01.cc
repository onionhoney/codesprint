//
//  main.cpp
//  CodeSprintLA
//
//  Created by Christopher Aziz on 1/28/17.
//  Copyright © 2017 Christopher Aziz. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

// include newline after each cout

int main() {
    

    int t;
    
    cin >> t;
    while(t > 0) {
        int p;
        cin >> p;
        int battery;
        cin >> battery;
        int beauty;
        int flowers;
        while(p > 0 && battery > 0) {
            int b;
            cin >> b;
            
            int bored;
            cin >> bored;
            while(bored > 0 && battery > 0) {
                beauty += b;
                bored--;
                battery--;
            }
            
            if (flowers >= p) break;
            p--;
        }
        cout << beauty << endl;
        
        t--;
    }
    return 0;
}
