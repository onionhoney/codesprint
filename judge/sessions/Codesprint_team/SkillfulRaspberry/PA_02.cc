//
//  main.cpp
//  codesprint
//
//  Created by Kedar Thiagarajan on 1/28/17.
//  Copyright © 2017 Kedar Thiagarajan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool contains (vector<char>characters, char c) {
    for (int j = 0; j < characters.size(); j++) {
        if (c == characters[j] )
            return true;
    }
    if (!isdigit(c)) {
        characters.push_back(c);
        return false;
      
    }
    return true;
}


int main(int argc, const char * argv[]) {
    
    int t = 0;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        string username;
        string lowerusername;
        cin >> username;
        for(int i = 0; i < username.length(); i++)
        {
            lowerusername += tolower(username[i]);
        }
        
        vector<char> characters;
        int unique = 0;
        for(int i = 0; i < lowerusername.length(); i++)
        {
            if(!contains(characters,lowerusername[i]))
               {
                   unique++;
                   characters.push_back(lowerusername[i]);
               }
        }
        
        if(unique%2 == 0)
            cout <<"INVITE TO PARTY" << endl;
        else
            cout <<"TRASH TALK THE USER" << endl;
        
    }
}