//
//  main.cpp
//  CodeSprintGroupA
//
//  Created by Neel Manthani on 1/28/17.
//  Copyright © 2017 Neel Manthani. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int count;
    string str;
    char ch;
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        count = 0;
        cin >> str;
        for (int i = 0; i < str.length(); i++)
        {
            count = 0;
            ch = str[i];
            for (int j = 0; j < str.length(); j++)
            {
                if (str[i] == str[j])
                    count++;
            }
            if (count % 2 == 0)
            {
                cout << "TRASH TALK THE USER" << endl;
                break;
            }
        }
        if (count % 2 == 1)
            cout << "INVITE TO PARTY" << endl;
    }
}
