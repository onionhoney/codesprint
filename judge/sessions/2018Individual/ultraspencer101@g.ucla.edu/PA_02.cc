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
        count = 0;
    }

    for (int i = 1; i <= combination.size(); i++){
        if (i%3 == 0){
            cout << combination[i-1] << endl;
        }
        else{
            cout << combination[i-1] << " ";
        }

    }
    
    return 0;
}
