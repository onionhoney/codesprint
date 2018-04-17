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
    cin.ignore(10000, '\n');
    int arr[100];
    int u = 0;
    while(t > 0) {
        string s;
        getline(cin, s);
        int i = 0;
        string abcd = "";
        for(int j = 0; j < s.length(); j++){
        
            
            if(isalpha(s[j]) && abcd.find(toupper(s[j]))==string::npos) {
                i++;
            }
            abcd += toupper(s[j]);
        }
        if(i % 2 == 0) {
            arr[u] = 1;
        }
        else {
            arr[u] = 0;
        }
        u++;
        t--;
        //cout << i << endl;

        i  = 0;
        
    }
    for(int r = 0; r < u; r++) {
        if(arr[r] == 1) {
            cout << "INVITE TO PARTY" << endl;
        } else
        cout << "TRASH TALK THE USER" << endl;

    }
    
}


