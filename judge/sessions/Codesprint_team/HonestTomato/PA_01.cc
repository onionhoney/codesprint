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
int main()
{
    
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        int count = 0;
        int countCopies = 0;
        string username;
        cin >> username;
       
        for(int i = 0; i < username.length(); i++)
        {
            bool found = false;
            if(isalpha(username[i]))
            {
                for(int j = 0; j < username.length(); j++)
                {
                    if(toupper(username[i] == toupper(username[j])))
                    {
                        countCopies++;
                        found = true;
                        break;
                    }
                }
                if(found == false)
                {
                    count++;
                }
                if (found == true && countCopies == 1)
                    count++;
            }
        }
        if(count % 2 == 0)
        {
            cout<< "INVITE TO PARTY";
        }
        else
            cout << "TRASH TALK THE USER";
    }
   
}
