#include <iostream>
#include <string>
#include <vector>
//#include <cmath>
//#include <sstream>
//#include <bitset>
using namespace std;

int maxBeautyIndex(vector<int> vec, vector<int> nums){
    int index = 0;
    for (int i = 1; i < vec.size(); i++){
        if (nums[index] == 0){
            vec[index] = 0;
        }
        if (vec[i] > vec[index] && nums[i] > 0){
            index = i;
        }
    }
    return index;
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
        
        vector<int> b; // beauty
        vector<int> nums; // number allowed
        
        for (int i = 0; i < p; i++){
            int bi = 0;
            int ni = 0;
            cin >> bi >> ni;
            b.push_back(bi);
            nums.push_back(ni);
        }
        
        int beauty = 0;
        bool terminate = false;
        for (int i = 0; i < n && !terminate; i++){
            int maxBeauty = maxBeautyIndex(b, nums);
            beauty += b[maxBeauty];
            nums[maxBeauty]--;
            terminate = true;
            for (int j = 0; j < p; j++){
                if (nums[j] > 0){
                    terminate = false;
                }
            }
        }
        cout << beauty << endl;
        
        cases++;
    }

    return 0;
}
