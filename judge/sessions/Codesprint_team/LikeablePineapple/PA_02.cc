//
//  main.cpp
//  teamA
//
//  Created by Lexie Kemp on 1/28/17.
//  Copyright © 2017 Lexie Kemp. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string output[100];
    int t;
    cin>>t;
    cin.ignore(1000,'\n');
    for (int x=0; x<t; x++)
    {
        string user;
        getline(cin, user);
        if (user.size()==1)
        {
            output[x]="TRASH TALK THE USER";
        }
        else{
            for (int a=0;a<user.size();a++)
            {
                if (isalpha(user[a]))
                {
                    for (int b=a+1;b<user.size();b++)
                    {
                        if (tolower(user[a])==tolower(user[b]))
                        {
                            user.erase(b,1);
                            b--;
                        }
                    }
                }
                else
                {
                    user.erase(a,1);
                    a--;
                }
            }
            if (user.size()%2==0)
                output[x]="INVITE TO PARTY";
            else
                output[x]="TRASH TALK THE USER";
        }
    }
    for (int c=0;c<t;c++)
    {
        cout<<output[c]<<endl;
    }
}
