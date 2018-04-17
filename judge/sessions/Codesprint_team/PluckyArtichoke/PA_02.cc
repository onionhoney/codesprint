//
//  main.cpp
//  CodeSprintLA
//
//  Created by Christopher Aziz on 1/28/17.
//  Copyright © 2017 Christopher Aziz. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>

using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int i;
        for(int j = 0; j < s.length(); j++){
            
            if(isalpha(s[i])) {
                i++;
            }
        }
        if(i % 2 == 0)
            cout << "INVITE TO PARTY" << endl;
        else
            cout << "TRASH TALK THE USER" << endl;
        
    }
    
}


