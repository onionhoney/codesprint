#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> combination;
    int locks;
    int count = 0;
    cin >> locks;
    
    for (int i = 0; i < locks; i++){
        while (count < 3){
            int check;
            for (int j = 0; j <= 99; j++){
                cin >> check;
                if (check == 1){
                    combination.push_back(j);
                }
            }
            count++;
        }
    }

    for (int i = 0; i < combination.size(); i++){
        cout << combination[i] << " ";
    }
    
    return 0;
}
