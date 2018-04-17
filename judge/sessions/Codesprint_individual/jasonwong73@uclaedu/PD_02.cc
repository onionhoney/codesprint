#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;


struct range{
    int l;
    int r;
    range(int a, int b){
        l = a;
        r = b;
    }
    range(){}
};

struct entry{
    range ran;
    char c;
    entry(range a, char b){
        ran = a;
        c = b;
    }
};

int main(){
       int iCount;
       cin>>iCount;
       vector<entry> instructions;
       
       for(int i = 0 ; i < iCount ; i++){
            int l,r;
            char c;
            cin>>l>>r >> c;
            if(l <= r){
                range tmpRange(l,r);
                entry tmpEntry(tmpRange, c);
                instructions.push_back(tmpEntry);
            }
            
       }

       int x1, x2, x3, x4;
       cin>>x1>>x2>>x3>>x4;
         
       int i;
       for(int x = 0 ; x < 4 ; x++){

            int currX;

            if(x == 0){
                currX = x1;
            }else if(x == 1){
                currX = x2;

            }else if(x == 2){
                currX = x3;

            }else{
                currX = x4;
            }

           for(i = instructions.size() - 1 ; i >= 0 ; i--){
                entry e = instructions[i];
                range ra = e.ran;
                int l = ra.l;
                int r = ra.r;
                if(l <= currX && r >= currX){
                    cout<< e.c;
                    break;
                }


           }
           if(i == -1){
                cout<< "a";
           }

           if( x != 3){
                cout<< " ";

           }else{
            cout << " " <<endl;
           }

       }




}
