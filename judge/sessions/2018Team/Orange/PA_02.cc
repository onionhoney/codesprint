#include <iostream>
#include <string>
using namespace std;

int main(){

    int t, n, k;
    cin >> t;

    for (int j = 0; j < t; j++){
	cin >> n >> k;
	string shots;
	//getline (cin, shots);
	cin >> shots;
	int count = 0;
	int consec = 0;
/*
	for (int i = 0; i < (n - 1);){
		while (shots[i] == shots[i+1]){
			consec++;
		}
		if (consec >= k){
			if (shots[i] == 'R')
				count--;
			if (shots[i] == 'L')
				count++;
		}
		i += consec;

	}
	cout << count << endl;
    }
    return 0;
}
*/




	
/*	for (int i= 0; i < (n-k); i++){
		bool match = false;
		for (int m = i; m < (i+(k-1)); m++){
			if (shots[m] == shots[m + 1])
				match = true;
			else{
			    match = false;
			    break;}
		}
		if (shots[i] == 'R' && match == true){
			count--; 
			//cout << "inc";
		}
		else if (shots[i] == 'L' && match == true){
			count++; 
			//cout << "dec";
		}
	}

	cout << count << endl;
*/
	
	int m = 0;
	
	for (int i = 0; i < n; i++) {
		if (shots[i] == 'R') {
			while (shots[i] == 'R' && m < k-1) {
				i++;
				m++;
			}
			if (m == k) {
				count--;
				cout << count << endl;
			}
			else m = 0;
		} else if (shots[i] == 'L') {
			while (shots[i] == 'L' && m < k-1) {
				i++;
				m++;
			}
			if (m == k) {
				count++;
				cout << count << endl;
			}
			else m = 0;
		}
	}

	cout << count << endl;
	}	
    
    
    return 0;
}
