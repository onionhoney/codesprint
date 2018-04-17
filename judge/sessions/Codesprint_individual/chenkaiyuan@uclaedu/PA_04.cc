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
		vector<int> v;
		int count=0;
		for(int i=0;i<n;i++){
			int j,b;
			cin>>b>>j;
			
			for(int u=0;u<j;u++){
				v.push_back(b);
				count++;
			}
		}
		
		sort(v.begin(),v.begin()+count);
		int sum=0;
		std::vector<int>::reverse_iterator rit = v.rbegin();
		
		for(int i=0;i<max&&rit!=v.rend();i++){
			sum=sum+(*rit);
			rit++;
		}
		cout<<sum<<endl;
	}
//	cout<<endl;
	return 0;
}
