#include <iostream>
#include <string>
#include <vector>
//#include <cmath>
//#include <sstream>
//#include <bitset>
using namespace std;

int maxBeautyIndex(vector<vector<int>> flowers){
    int maxIndex = 0;
    int count = 0;
    for (int i = 0; i < flowers.size(); i++){
        count += flowers[i][1];
        if (flowers[i][0] > flowers[maxIndex][0] || flowers[maxIndex][1] == 0){
            maxIndex = i;
        }
    }
    if (count == 0){
        return -1;
    }
    return maxIndex;
}

int main(int argc, const char * argv[])
{
    int t = 0; // number of test cases
    cin >> t;
    int cases = 0;
    while (cases < t){
        int p = 0; // number of flowers
        int n = 0; // number can be drawn after
        cin >> p >> n;
        
        vector<vector<int>> flowers;
        
        for (int i = 0; i < p; i++){
            int bi = 0;
            int ni = 0;
            cin >> bi >> ni;
            vector<int> pair;
            pair.push_back(bi);
            pair.push_back(ni);
            flowers.push_back(pair);
        }
        
        int beauty = 0;
        
        for (int i = 0; i < n; i++){
            if (maxBeautyIndex(flowers) < 0){
                break;
            }
            beauty += flowers[maxBeautyIndex(flowers)][0];
            flowers[maxBeautyIndex(flowers)][1]--;
        }
        
        cout << beauty << endl;
        
        cases++;
    }

    return 0;
}
