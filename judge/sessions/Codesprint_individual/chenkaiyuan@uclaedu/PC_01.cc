#include <bits/stdc++.h>
using namespace std;


int main(){
	int test;
	cin>>test;
	char c[105][105];
	bool b[105][105];
	for(int t=0;t<test;t++){
		int m,n;
		cin>>m>>n;
		int m1,n1;
		cin>>m1>>n1;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>c[m][n];
			}
		}
		
		bool flag=false;
		string s;
		while(flag!=true){
			if(c[m1+1][n1]=='#'){
				c[m1+1][n1]='.';
				s=s+"R";
				m1=m1+1;
			}else if(c[m1-1][n1]=='#'){
				c[m1+1][n1]='.';
				s=s+"L";
				m1=m1-1;
			}else if(c[m1][n1+1]=='#'){
				c[m1][n1+1]='.';
				s=s+"U";
				n1=n1+1;
			}else if(c[m1][n1-1]=='#'){
				c[m1][n1-1]='.';
				s=s+"D";
				n1=n1-1;
			}else{
				flag=true;
			}
				
		}
		cout<<s<<endl;
	}
	
	return 0;
}
