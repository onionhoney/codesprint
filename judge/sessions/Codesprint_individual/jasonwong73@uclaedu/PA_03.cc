#include <algorithm>
#include <string>
#include <iostream>
using namespace std;



int main(){
    int t;
    cin >> t;

    for(int i = 0 ; i < t; i++){
        int flowerTypes;
        int flowerLeft;
        cin>>flowerTypes;
        cin>>flowerLeft;
        
        int count = 0;

        for(int l = 0 ; l < flowerTypes; l++){
            if(flowerLeft == 0){
                break;
            }

            int value;
            int num;

            cin>>value;
            cin>>num;
            
            if(flowerLeft - num > 0){
                count += (num * value);
                flowerLeft -= num;
            }else{
                count += (flowerLeft * value);
                flowerLeft = 0;
            }

        }

        cout<<count<<endl;
    }

}
