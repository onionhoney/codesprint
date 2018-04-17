//
//  a.cpp
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
            int nflow;
            int bl;
            cin>>nflow>>bl;
            int a=0;
            for(int i=0;i<nflow;i++){
                int beau;
                int num;
                cin>>beau>>num;
                while(bl>0 && num>0){
                    a+=beau;
                    bl--;
                    num--;
                }
            }
            cout<<a<<endl;
        }
    return 0;
}

//int main(){
//    int t;
//    cin>>t;
//    for(int c=0;c<t;c++){
//        int nflow;
//        int bl;
//        cin>>nflow>>bl;
//        int arr[1005];
//        for(int i=0;i<1000;i++)
//            arr[i]=0;
//        for(int i=0;i<nflow;i++){
//            int beau;
//            int num;
//            cin>>beau>>num;
//            arr[beau]=num;
//        }
//        long a=0;
//        for(int i=1000;i>=1;i--){
//            if(bl<=0)
//                break;
//            while(bl>0&&arr[i]>0){
//                bl--;
//                a+=i;
//                arr[i]--;
//            }
//        }
//        cout<<a<<endl;
//    }
//    return 0;
//}
