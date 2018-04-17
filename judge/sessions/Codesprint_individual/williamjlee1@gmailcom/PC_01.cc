//
//  c.cpp
//  csw
//
//  Created by William Lee on 1/28/17.
//  Copyright © 2017 williamlee. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string rec(string sof, int x,int y, bool v[][100],char c[][100],int m,int n){
    int dirs[4][2]={
        {-1,0},{1,0},{0,-1},{0,1}
    };
    for(int i=0;i<4;i++){
        if(x+dirs[i][0]>=0&&x+dirs[i][0]<m&&y+dirs[i][1]>=0&&y+dirs[i][1]<n){
            if(c[x+dirs[i][0]][y+dirs[i][1]]=='#' && !v[x+dirs[i][0]][y+dirs[i][1]]){
                if(i==0){
                    v[x-1][y]=true;
                    return rec(sof+"U",x-1,y,v,c,m,n);
                    v[x-1][y]=false;
                }
                if(i==1){
                    v[x+1][y]=true;
                    return rec(sof+"D",x+1,y,v,c,m,n);
                    v[x+1][y]=false;
                }
                if(i==2){
                    v[x][y-1]=true;
                    return rec(sof+"L",x,y-1,v,c,m,n);
                    v[x][y-1]=false;
                }
                if(i==3){
                    v[x][y+1]=true;
                    return rec(sof+"R",x,y+1,v,c,m,n);
                    v[x][y+1]=false;
                }
            }
        }
    }
    return sof;
}

int main(){
    int t;
    cin>>t;
    for(int c=0;c<t;c++){
        int m,n;
        cin>>m>>n;
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        bool v[m][100];
        for(int i=0;i<m;i++){
            for(int j=0;j<100;j++)
                v[i][j]=false;
        }
        v[x][y]=true;
        string s;
        char cm[m][100];
        for(int i=0;i<m;i++){
            cin>>s;
            for(int j=0;j<n;j++){
                cm[i][j]=s[j];
            }
        }
        string str="";
        cout<<rec(str,x,y,v,cm,m,n)<<endl;
    }
    
    return 0;
}
