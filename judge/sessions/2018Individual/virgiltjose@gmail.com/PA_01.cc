#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    int numTests = 0;
    cin >> numTests;
    
    int outputs[numTests];
    
    // FOR EACH TEST CASE
    for(int i = 0; i < numTests; i++) {
        
        // num times can jump
        int possJumps = 0; cin >> possJumps;
        // num options for each class
        int numopt31 = 0, numopt32 = 0;
        cin >> numopt31 >> numopt32;
        
        // list of options
        int opt31[numopt31]; int opt32[numopt32];
        for(int j = 0; j < numopt31; j++)
            scanf("%d", &opt31[j]);
        for(int k = 0; k < numopt32; k++)
            scanf("%d", &opt32[k]);

        // calculate the max number for 31
        int max31 = 0;
        vector<int> sortedOpt31(opt31, opt31 + numopt31);
        sort(sortedOpt31.begin(), sortedOpt31.begin() + numopt31);

        // calculate the max number for 32
        vector<int> sortedOpt32(opt32, opt32 + numopt32);
        sort(sortedOpt32.begin(), sortedOpt32.begin() + numopt32);
        
        int index31 = numopt31;
        int maxtotal = 0;
        while(index31 != 0) {
            
            int checktotal = 0;
            
            for(int x = 0; x < numopt32; x++) {
                max31 = opt31[numopt31 - 1];
                checktotal = max31 + sortedOpt32[x];
                if(checktotal < possJumps && checktotal > maxtotal)
                    maxtotal = checktotal;
            }
            index31--;
        }
        outputs[i] = maxtotal;
    }
    
    for(int l = 0; l < numTests; l++)
        cout << outputs[l] << endl;
    
    
}


//INPUT
// # test cases

// # times can jump
// # options 31, # options 32
// class sizes 31 to choose from
// class sizes 32 to choose from
