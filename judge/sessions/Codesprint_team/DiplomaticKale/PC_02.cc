#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int results[t];
    for (int i = 0; i < t; i++)
        results[i] = -1;
    for (int i = 0; i < t; i++) {
        int length, numtraffic, speedlim;
        cin >> length >> numtraffic >> speedlim;
        int pos[numtraffic], period[numtraffic];
        for (int j = 0; j < numtraffic; j++)
            cin >> pos[j] >> period[j];
        int speed;
        for (speed = speedlim; speed >= 10; speed--) {
            bool flag = true;
            for (int j = 0; j < numtraffic; j++)
                if ( ((pos[j] / speed) / period[j]) % 2 ) {
                    flag = false;
                    break;
                }
            if (flag) {
                results[i] = speed;
                break;
            }
        }
        
    }
    
    for (int i = 0; i < t; i++)
        cout << results[i] << endl;
    
        
    
}
