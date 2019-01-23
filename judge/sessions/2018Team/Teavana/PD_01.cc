#include <iostream>
#include <vector>
#include <string>

using namespace std;

int chose (int start, vector<int>& lists, vector<string>&chosen){
    int max = 0;

    for (int i = start; i < lists.size(); i++){
        if (i == start && chosen[i] != "y"){
            chosen[i] = "y";
            //cout << lists[i] << "!!";
            if (lists[i] > max){
                max = lists[i];
            }
        }
        else if (i == lists.size()-1 && chosen[i-1] != "y"){
            chosen [i] = "y";
            //cout << lists[i] << "!!";
            if (lists[i] > max){
                max = lists[i];
            }
        }
        else if (chosen[i] != "y" && chosen[i-1] !="y" && chosen[i+1] !="y"){
            chosen [i] = "y";
            //cout << lists[i] << "!!";
            if (lists[i] > max){
                max = lists[i];
            }
        }
    }
    return max;
}


int main(){
    vector<int>total;
    int cases;
    cin >> cases;
    
    for (int i = 0; i < cases; i++){
        int districts;
        int contestants;
        int max = 0;
        vector<int>lists;
        vector<string>chosen;
        cin >> districts >> contestants;
        
        for (int j = 0; j < districts; j++){
            int input;
            cin >> input;
            lists.push_back(input);
            chosen.push_back("x");
        }
        
        
        for (int x = 0; x < districts-contestants; x++){
            int sum = 0;
            
            for (int y = 0; y < contestants; y++){
                sum += chose(x, lists, chosen);
                //cout << sum << "//";
            }
            if (sum > max){
                max = sum;
            }
            for (int z = 0; z < districts; z++){
                chosen[z] = "x";
            }
            
        }
        
        total.push_back(max);
        
    }
    
    for (int i = 0; i < total.size(); i++){
        cout << total[i] << endl;
    }
    
    return 0;
}
