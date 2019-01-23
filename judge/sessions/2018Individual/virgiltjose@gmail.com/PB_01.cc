#include <iostream>
using namespace std;

int main() {

    int numberLocks;
    cin >> numberLocks;
    
    for(int i = 0; i < numberLocks; i++) {
        
        int firstNum[100];
        int secondNum[100];
        int thirdNum[100];
        
        int first, second, third = 0;
        
        for(int j = 0; j < 100; j++) {
            scanf("%d", &firstNum[j]);
            if(firstNum[j] == 1) {
                first = j;
//                break;
            }
        }
        for(int k = 0; k < 100; k++) {
            scanf("%d", &secondNum[k]);
            if(secondNum[k] == 1) {
                second = k;
//                break;
            }
        }
        for(int m = 0; m < 100; m++) {
            scanf("%d", &thirdNum[m]);
            if(thirdNum[m] == 1) {
                third = m;
//                break;
            }
        }
        
        cout << first << " " << second << " " << third << endl;
    }
    
    
    return 0;
}
