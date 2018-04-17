//
//  main.cpp
//  B
//
//  Created by Lexie Kemp on 1/28/17.
//  Copyright © 2017 Lexie Kemp. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    string output="";
    for (int x=0;x<t;x++)
    {
        int h=1;
        int v=1;
        int one, two, k;
        cin>>one>>two>>k;
        for (int a=0;a<k;a++)
        {
            int x1, x2, x3, x4;
            cin>>x1>>x2>>x3>>x4;
            if (x1 != x3)
                v++;
            else
                h++;
        }
        if (output != "")
            output+=to_string(h*v)+'\n';
        else
            output=to_string(h*v)+'\n';
    }
    cout<<output<<endl;
}
