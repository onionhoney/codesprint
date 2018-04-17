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
    int len=1000001;
    int arr[1000001];
    for(int i=0;i<=1000000;i++)
        arr[i]=0;
    arr[0]=1;
    arr[1]=1;
    arr[2]=1;
    arr[3]=1;
    int dlen=0;
    for(int c=0;c<t;c++){
        int n;
        cin>>n;
        int a=1;
        for(int i=0;i<n;i++){
            int si;
            cin>>si;
            if(si<=dlen){
                a=(a*arr[si])%10007;
                
            }
            else
            {
                for(int i=dlen+1;i<=si;i++){
                if(arr[i]>0){
                    if(i+1<len)
                        arr[i+1]=(arr[i]+arr[i+1])%10007;
                    if(i+2<len)
                        arr[i+2]=(arr[i]+arr[i+2])%10007;
                    if(i+3<len)
                        arr[i+3]=(arr[i]+arr[i+3])%10007;
                }
                }
                dlen=si;
                a=(a*arr[si])%10007;
            }

        }
        cout<<a<<endl;
        
    }
    
    return 0;
}

//            for(int j=0;j<si+1;j++)
//                arr[j]=0;
//            arr[0]=1;
//            for(int j=0;j<si+1;j++){
//                if(arr[j]>0){
//                    if(j+1<si+1)
//                        arr[j+1]=(arr[j+1]+arr[j])%10007;
//                    if(j+2<si+1)
//                        arr[j+2]=(arr[j+2]+arr[j])%10007;
//                    if(j+3<si+1)
//                        arr[j+3]=(arr[j+3]+arr[j])%10007;
//                }
//            }
//            a=(a*arr[si])%10007;
