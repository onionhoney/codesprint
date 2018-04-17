//  Created by Aidan Wolk on 1/28/17.
//  Copyright © 2017 Aidan Wolk. All rights reserved.
//

#include <iostream>

using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int count=0;
        int rows;
        int cols;
        cin >> rows;
        cin >> cols;
        int arr[1001][1001];
        for(int k=0;k<1001;k++){
            for(int j=0;j<1001;j++){
                arr[k][j] = 0;
            }
        }
        int qw;
        cin >> qw;
        for(int q=0;q<qw;q++){
            int x,y;
            cin >> x;
            cin >> y;
            arr[x][y] = 10;
        }
        for(int pop=1;pop<=rows;pop++){
            for(int opp=1;opp<=cols;opp++){
                if(arr[pop][opp]>=10){
                    arr[pop-1][opp-1]++;
                    arr[pop][opp-1]++;
                    arr[pop-1][opp]++;
                    arr[pop+1][opp-1]++;
                    arr[pop-1][opp+1]++;
                    arr[pop+1][opp+1]++;
                    arr[pop][opp+1]++;
                    arr[pop+1][opp]++;
                }
            }
        }
        for(int qqq=1;qqq<=rows;qqq++){
            for(int www=1;www<=cols;www++){
                if(arr[qqq][www]<=8 && arr[qqq][www] > 0){
                    count+=arr[qqq][www];
                }
            }
        }
        cout << count << endl;
    }
}
