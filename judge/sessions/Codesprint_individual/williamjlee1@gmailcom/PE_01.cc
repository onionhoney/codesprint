//
//  e.cpp
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
        int n;
        cin>>n;
        int a=1;
        for(int i=0;i<n;i++){
            int si;
            cin>>si;
            int arr[si+1];
            for(int j=0;j<si+1;j++)
                arr[j]=0;
            arr[0]=1;
            for(int j=0;j<si+1;j++){
                if(arr[j]>0){
                    if(j+1<si+1)
                        arr[j+1]=(arr[j+1]+arr[j])%10007;
                    if(j+2<si+1)
                        arr[j+2]=(arr[j+2]+arr[j])%10007;
                    if(j+3<si+1)
                        arr[j+3]=(arr[j+3]+arr[j])%10007;
                }
            }
            a=(a*arr[si])%10007;
        }
        cout<<a<<endl;
        
    }
    
    return 0;
}
