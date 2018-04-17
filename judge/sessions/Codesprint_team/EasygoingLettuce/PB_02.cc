//
//  b.cpp
//  cswt
//
//  Created by William Lee on 1/28/17.
//  Copyright © 2017 williamlee. All rights reserved.
//

#include <string>
#include <iostream>
using namespace std;
int main(){
    
    int t;
    cin>>t;
    
    int dir[8][2]={
        {-1,0},{-1,1},{-1,-1},
        {1,0},{1,1},{1,-1},
        {0,1},{0,-1}
    };
    for(int c=0;c<t;c++){
        
        int m,n;
        cin>>m>>n;
        int num;
        cin>>num;
        int arr[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=0;
            }
        }
        int xar[num];
        int yar[num];
        
        for(int i=0;i<num;i++){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            arr[x][y]=-1;
            xar[i]=x;
            yar[i]=y;
        }
        long a=0;
        for(int i=0;i<num;i++){
            for(int j=0;j<8;j++){
                int newx=xar[i]+dir[j][0];
                int newy=yar[i]+dir[j][1];
                if(newx>=0&&newx<m&&newy>=0&&newy<n && arr[newx][newy]!=-1){
                    a++;
                }
                
            }
        }
        cout<<a<<endl;
    }
    return 0;
}
//        int m,n;
//        cin>>m>>n;
//        int arr[m][n];
//        for(int i=0;i<m;i++){
//            for(int j=0;j<n;j++){
//                arr[i][j]=0;
//            }
//        }
//        int num;
//        cin>>num;
//        for(int i=0;i<num;i++){
//            int x;
//            cin>>x;
//            int y;
//            cin>>y;
//            x--;
//            y--;
//            arr[x][y]=-1;
//        }
//        for(int i=0;i<m;i++){
//            for(int j=0;j<n;j++){
//                if(arr[i][j]<0){
//                    for(int k=0;k<8;k++){
//                        int newx=i+dir[k][0];
//                        int newy=j+dir[k][1];
//                        if(newx>=0&&newx<m&&newy>=0&&newy<n && arr[newx][newy]>=0){
//                            arr[newx][newy]++;
//                        }
//                    }
//                }
//            }
//        }
    
