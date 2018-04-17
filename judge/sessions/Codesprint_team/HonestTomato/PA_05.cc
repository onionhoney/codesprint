//
//  Team1.cpp
//  CodeSprint
//
//  Created by Ritesh Pendekanti on 1/28/17.
//  Copyright © 2017 Ritesh Pendekanti. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;
void remove(string& s, char x)
{
    
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == x)
        {
            s.erase(i,1);
            i--;
        }
    }
}
int main()
{
    
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        int removeCount = 0;
        int restCount = 0;
        int totalCount;
        string username;
        cin >> username;
       
        for(int i = 0; i < username.length(); i++)
        {
        
        for(int j = 0; j < username.length(); j++)
                {
                if(isalpha(username[i])){
                   if(username[i] == username[j])
                   {
                       removeCount++;
                       remove(username, username[i]);
                   }
                }
                }
            
        }
        for (int k = 0; k < username.length(); k++)
        {
            if(isalpha(username[k]))
               {
                   restCount++;
               }
        }
        totalCount = restCount + removeCount;
        if(totalCount % 2 == 0)
        {
            cout<< "INVITE TO PARTY";
        }
        else
            cout << "TRASH TALK THE USER";
    }
   
}
