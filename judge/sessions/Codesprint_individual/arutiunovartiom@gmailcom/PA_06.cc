#include <iostream>

using namespace std;


struct flower {
    int beauty;
    int type;
};

int main(int argc, const char * argv[]) {
    int numtestCases = 0;
   // cout << "Enter the # of test cases\n";
    cin >> numtestCases;
    for (int i = 0; i < numtestCases; i++) {
        int numTypeFlowers, numFlowers = 0;
        cin >> numTypeFlowers >> numFlowers;
        flower array [numTypeFlowers];
        for (int z = 0; z < numTypeFlowers; z++) {
            int bea, ty;
            cin >> bea >> ty;;
            array[z].beauty=bea;
            array[z].type=ty;
        }
        int sum = 0;
        int count = 0;
        for (int i = 0; i < numTypeFlowers; i++) {
            if ((array[i].type + count) > numFlowers)
            {
                for (int k = 0; k < numFlowers - count; k++)
                    sum += array[i].beauty;
                break;
            }
            
            for (int j = array[i].type; j > 0; j--){
                sum += array[i].beauty;
                count++;
            }
        }
        cout << sum << "\n";
    }
}

