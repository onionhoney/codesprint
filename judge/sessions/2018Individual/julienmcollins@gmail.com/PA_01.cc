#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Read each input line from stdin
    int num_test_cases;
    cin >> num_test_cases;
    bool found_test = true;

    // Local variables
    int num_of_jumps = 0;
    int num_in_class[2];
    int *cs31;
    int *cs32;
    int max[num_test_cases] = {0 , 0};
    bool compute = false;

    // Loop through the data
    for (int i = -1; i < (num_test_cases * 4); i++) {
        //cout << "i = " << i << endl;
        //cout << "compute = " << compute << endl;
        // Get cin
        string input;
        stringstream ss;
        getline (cin, input);
        ss << input;
        //cout << input << endl;

        string temp;
        int num;

        // Get number of jumps through modulo
        if (i % 4 == 0) {
            //cout << "0" << endl;
            stringstream(input) >> num_of_jumps;
            //cout << num_of_jumps << endl;
            compute = true;
            continue;
        }

        // Get number of options for each class
        if (i % 4 == 1) {
            //cout << "1" << endl;
            int x = 0;
            while (!ss.eof()) {
                ss >> temp;
                if (stringstream(temp) >> num) {
                    num_in_class[x] = num;
                    //cout << "---" << num_in_class[x] << endl;
                }
                temp = "";
                x++;
            }
        }

        // Get the number of stuff
        if (i % 4 == 2) {
            //cout << "2" << endl;
            //cout << "---" << num_in_class[0] << endl;
            if (!cs31) {
                delete [] cs31;
            }
            cs31 = new int[num_in_class[0]];
            int x = 0;
            while (!ss.eof()) {
                ss >> temp;
                if (stringstream(temp) >> num) {
                   cs31[x] = num;
                   //cout << "----" << cs31[x] << endl;
                }
                temp = "";
                x++;
            } 
        }

        if (i % 4 == 3) {
            //cout << "3" << endl;
            //cout << "---" << num_in_class[1] << endl;
            if (!cs32) {
                delete [] cs32;
            }
            cs32 = new int[num_in_class[1]];
            int x = 0;
            while (!ss.eof()) {
                ss >> temp;
                if (stringstream(temp) >> num) {
                   cs32[x] = num;
                   //cout << "----" << cs32[x] << endl;
                }
                temp = "";
                x++;
            } 
        
            //cout << "num_in_class[0] = " << num_in_class[0] << endl;
            //cout << "num_in_class[1] = " << num_in_class[1] << endl;

            for (int j = 0; j < num_in_class[0]; j++) {
                //cout << "cs31[" << j << "] = " << cs31[j] << endl; 
                for (int k = 0; k < num_in_class[1]; k++) {
                    //cout << "cs32[" << k << "] = " << cs32[k] << endl; 
                    //cout << (i/4) << endl;
                    if ((cs31[j] + cs32[k]) <= num_of_jumps && (cs31[j] + cs32[k] > max[(i/4)])) {
                        max[(i/4)] = cs31[j] + cs32[k];
                    }
                }
            }
        }
    }

    for (int i = 0; i < num_test_cases; i++) {
        cout << max[i] << endl;
    }
}
