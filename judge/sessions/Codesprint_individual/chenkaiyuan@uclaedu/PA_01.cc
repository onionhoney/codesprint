#include <bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin>>t;
	for(int k=t;k>0;k--){
		int n;
		cin>>n;
		int max;
		cin>>max;
		multiset<int> s;
		for(int i=0;i<n;i++){
			int j;
			cin>>j;
			int times;
			cin>>times;
			for(int u=0;u<times;u++){
				s.insert(j);
			}
		}
		
		multiset<int>::reverse_iterator rit=s.rbegin();
		int sum=0;
		for(int i=0;i<max&&rit!=s.rend();i++){
			sum=sum+(*rit);
			rit++;
		}
		cout<<sum<<endl;
	}
//	cout<<endl;
	return 0;
}
