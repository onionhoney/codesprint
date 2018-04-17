//
//  main.cpp
//  CodesprintLA Adventure Time
//
//  Created by Yizhu Zhang on 1/28/17.
//  Copyright © 2017 Yizhu Zhang. All rights reserved.
//

#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main(int argc, const char * argv[]) {
    int tc;
    cin >> tc;
    string* output = new string[tc];
    for (int i = 0; i < tc; i++)
    {
        bool container[26];
        for (int i = 0; i < 26; i++)
            container[i] = false;
        string ans = "";
        string s;
        getline(cin,s);
        for (int j = 0; j < s.length(); j++)
        {
            if (isalpha(s[j]))
            {
                s[j] = toupper(s[j]);
                if(!container[s[j]-'A']){
                    container[s[j]-'A'] = true;
                    ans += s[j];
                }
            }
        }
        if (ans.length() % 2)
            output[i] = "INVITE TO PARTY";
        else
            output[i] = "TRASH TALK THE USER";
    }
    for (int i = 0; i < tc; i++)
        cout << output[i] << endl;
}
