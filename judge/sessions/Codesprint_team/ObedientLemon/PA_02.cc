//
//  main.cpp
//  adventuretime
//
//  Created by Kevin Tat on 1/28/17.
//  Copyright © 2017 Kevin Tat. All rights reserved.
//

#include <iostream>
#include <cctype>
#include <vector>
#include <iterator>
#include <string>

using namespace std;


int pq_plz(string user){
    int length = user.size();
    if (length == 0){
//        cout<< "TRASH TALK THE USER";
        return 0;
    }
    // lower case everything
    for (int i = 0; i < length; i++){
        user[i] = tolower(user[i]);
    }
    int sum = 0;
    vector<char> already_in;
    
    sum += 1;
    already_in.push_back(user[0]);
    
    for (int j = 1; j < length; j++){
        bool in = false;
        for (int k = 0; k < already_in.size(); k++){
            if (user[j] == already_in[k]){
                in = true;
            }
        }
        if (!in && !isdigit(user[j])){
            already_in.push_back(user[j]);
            sum++;
        }
    }
    
    if (sum % 2 == 0){
        return 1;
    }
    else
        return 0;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> response;
    int t;
    cin >> t;
    cin.ignore(10000,'\n');
    for (int i = 0; i < t; i++){
        string username;
        int result;
        getline(cin, username);
        result = pq_plz(username);
        if (result == 0){
            response.push_back("TRASH TALK THE USER");
        }
        else
            response.push_back("INVITE TO PARTY");
    }
    
    for (int p = 0; p < response.size(); p++){
        cout << response[p] << endl;
    }
    return 0;
}
