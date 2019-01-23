#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> all_cases;
    
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++){
        int jumps;
        int CS31;
        int CS32;
        vector<int> CS31_size;
        vector<int> CS32_size;
        cin >> jumps;
        cin >> CS31 >> CS32;
        
        for (int x = 0; x < CS31; x++){
            int input;
            cin >> input;
            CS31_size.push_back(input);
        }
        for (int y = 0; y < CS32; y++){
            int input;
            cin >> input;
            CS32_size.push_back(input);
        }
        
        int max = 0;
        for (int a = 0; a < CS31_size.size(); a++){
            for (int b = 0; b < CS32_size.size(); b++){
                if (CS31_size[a] + CS32_size[b] > max && CS31_size[a] + CS32_size[b] <= jumps){
                    max = CS31_size[a] + CS32_size[b];
                }
            }
        }
        
        all_cases.push_back(max);
        CS31_size.clear();
        CS32_size.clear();
    }
    
    for (int r = 0; r < all_cases.size(); r++){
        cout << all_cases[r] << endl;
    }
    
    return 0;
}
