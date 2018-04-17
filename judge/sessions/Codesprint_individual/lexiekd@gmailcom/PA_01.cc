//
//  main.cpp
//  A
//
//  Created by Lexie Kemp on 1/28/17.
//  Copyright © 2017 Lexie Kemp. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin>>t;
    int count=0;
    int beauty=0;
    string output="";
    for (int x=0;x<t;x++)
    {
        int temp0;
        int temp2;
        cin>>temp0>>temp2;
        for (int a=0;a<temp0;a++)
        {
            int next0;
            int next2;
            cin>>next0>>next2;
            if ((count+(next2))>temp2)
            {
                beauty+=(next0)*(temp2-count);
                break;
            }
            else
            {
                beauty+=(next0)*(next2);
                count+=next2;
            }
        }
        if (output != "")
            output+=to_string(beauty)+'\n';
        else
            output=to_string(beauty)+'\n';
        count=0;
        beauty=0;
    }
    cout<<endl<<output<<endl;
    
}
