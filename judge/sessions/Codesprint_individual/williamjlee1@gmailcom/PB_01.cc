//
//  b.cpp
//  csw
//
//  Created by William Lee on 1/28/17.
//  Copyright © 2017 williamlee. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    for(int c=0;c<t;c++){
        int m;
        int n;
        cin>>m>>n;
        int numl;
        cin>>numl;
        int xl=0;
        int yl=0;
        for(int i=0;i<numl;i++){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            if(x1==x2){
                xl++;
            }
            if(y1==y2)
                yl++;
        }
        cout<<(yl+1)*(xl+1)<<endl;

    }
    return 0;
}
