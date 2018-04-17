//
//  main.cpp
//  teamC
//
//  Created by Lexie Kemp on 1/28/17.
//  Copyright © 2017 Lexie Kemp. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    cin.ignore(1000,'\n');
    int output[100];
    for (int x=0; x<t; x++)
    {
        bool pass=true;
        bool failed=true;
        int d,n,r;
        cin>>d>>n>>r;
        int lights[n][2];
        for (int b=0;b<n;b++) //create array of lights
        {
            int l,p;
            cin>>l>>p;
            lights[b][0]=l;
            lights[b][1]=p;
        }
        for (int s=r; s>0; s--) //go through each speed possibility
        {
            for (int c=0;c<n;c++) //go through leach light to check
            {
                int time=lights[c][0]/s;
                int num=time/lights[c][1];
                if (num%2!=0)
                    pass=false;
            }
            if (pass==true)
            {
                output[x]=s;
                failed=false;
                break;
            }
            pass=true;
        }
        if (failed==true)
            output[x]=-1;
    }
    for (int d=0;d<t;d++)
    {
        cout<<output[d]<<endl;
    }
}
