//
//  d.cpp
//  cswt
//
//  Created by William Lee on 1/28/17.
//  Copyright © 2017 williamlee. All rights reserved.
//

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class nod{
    
public:
    vector<int> v;
    nod(){
    }
};

long rec(nod* arr, int cur, bool pok[],bool vis[]){
    long m=-1;
    for(int i=0;i<arr[cur].v.size();i++){
        if(!vis[arr[cur].v[i]]){
            vis[arr[cur].v[i]]=true;
        long x=rec(arr,arr[cur].v[i],pok,vis);
            vis[arr[cur].v[i]]=false;
        if(x > m){
            m=x;
        }
        }
    }
    long a=m;
    if(pok[cur]){
        a++;
    }
    return a;
}

int main(){
    int t;
    cin>>t;
    for(int c=0;c<t;c++){
        int n,p,e;
        cin>>n>>p>>e;
        bool pok[n];
        for(int i=0;i<n;i++)
            pok[i]=false;
        for(int i=0;i<p;i++){
            int x;
            cin>>x;
            pok[x]=true;
        }
        nod* arr = new nod[n];
        for(int i=0;i<e;i++){
            int a,b;
            cin>>a>>b;
            arr[a].v.push_back(b);
            arr[b].v.push_back(a);
        }
        bool vis[n];
        for(int i=0;i<n;i++)
            vis[i]=false;
        vis[0]=true;
        cout<<rec(arr,0,pok,vis)+1<<endl;
        delete[]arr;
    }
    return 0;
}
