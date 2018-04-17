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
    int arr [10000];
    
    int t;
    int g = 0;
    cin >> t;
    while(t > 0) {
        int types;
        cin >> types;
        int battery;
        cin >> battery;
        
        
        int beauty = 0;
        while(types > 0) {
            int b;
            cin >> b;
            
            int bored;
            cin >> bored;
            while(bored > 0 && battery > 0) {
                beauty += b;
                bored--;
                battery--;

            }
            
            types--;
        }
        
        arr[g++] = beauty;
        t--;
    }
    
    for(int i = 0; i < g; i++) {
        cout << arr[i] << endl;
    }

    
    return 0;
    
}
