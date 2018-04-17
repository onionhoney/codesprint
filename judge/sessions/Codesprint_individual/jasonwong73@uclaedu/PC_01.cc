#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;


bool isValid(int r, int c, int m, int n){
    return (r >= 0 && r < m && c >= 0 && c < n);
}


int main(){
    int cases;
    cin>> cases;

    for(int ca = 0 ; ca < cases ; ca++){
        int m;
        int n;
        cin>>m>>n;
        int startR;
        int startC;
        cin>>startR>>startC;
        cin.get();
        vector<string> map;
         
        for(int myR = 0 ; myR < m ; myR++){
            string tmp;
            getline(cin, tmp);
            map.push_back(tmp);
        }


        int hashCount = 0;
        for(int a = 0 ; a < map.size() ; a++){
            for(int q = 0;q < map[0].size() ; q++){
                if(map[a][q] == '#'){
                    hashCount++;
                }   
            }

        }
        startR--;
        startC--;
        //cout<<startR<<endl<<startC<<endl<<map[startR][startC]<<endl;

        string ans = "";
        int currR = startR;
        int currC = startC;
        for(int i = 0 ; i < hashCount ; i++){
        /*for(int q = 0 ; q < map.size() ; q++){
            cout<<map[q]<<endl;
        }
            cout<<endl<<endl<<endl;
            */
            if(isValid(currR, currC-1, m, n)){
                if(map[currR][currC-1] == '#'){
                    ans += "L";
                currC--;
                map[currR][currC] = 'd';
                continue;
                }
            }

            if(isValid(currR, currC+1, m, n)){
                if(map[currR][currC+1] == '#'){
                    ans += "R";
                currC++;
                map[currR][currC] = 'd';
                continue;
                }
            }
            if(isValid(currR-1, currC, m, n)){
                if(map[currR-1][currC] == '#'){
                    ans += "U";
               currR--;
                map[currR][currC] = 'd';
                continue;
                }
            }
            if(isValid(currR+1, currC, m, n)){
                if(map[currR+1][currC] == '#'){
                    ans += "D";
                currR++;
                map[currR][currC] = 'd';
                continue;
                }

            }
        }

        cout<<ans<<endl;
        
    }

}
