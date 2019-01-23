#include <iostream>

using namespace std;

int calcOpt(int num_districts, int num_contestants, int population[]) {
        // Algorithm for determining the output
        int n = num_districts + 1;
        int k = num_contestants + 1;
        int opt[k][n];
        int count[k][n];

        // Loop through all n for k = 0
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < n; y++) {
                opt[x][y] = 0;
                count[x][y] = 0;
            }
        }

        // Initialize the column
        opt[1][1] = population[0];
        count [1][1]= 1;

        // Start algorithm
        for (int x = 1; x < k; x++) {
            for (int y = 2; y < n; y++) {
                // Calculate case 1 and case 2
                int c1 = opt[x-1][y-2] + population[y-1];
                int c2 = opt[x][y-1];


                // Calculate max and set opt
                if (c1 > c2) {
                    opt[x][y] = c1;
                    count[x][y]= count[x-1][y-2] + 1;
                } else {
                    opt[x][y] = c2;
                }
            }
        }
        
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < n; y++) {
                //cout << opt[x][y] << " ";
            }
            //cout << endl;
        }
        
        return opt[k-1][n-1];
}

int main() {
    // Get the number of test cases
    int num_test_cases;
    cin >> num_test_cases;

    // Loop through each test case
    for (int i = 0; i < num_test_cases; i++) {
        // Get the district num and number of contestants
        int num_districts;
        int num_contestants;
        cin >> num_districts >> num_contestants;

        // Array to store the population
        int population[num_districts];

        // Loop through the population numbers
        for (int j = 0; j < num_districts; j++) {
            // cin the district populations
            cin >> population[j];
        }
        if (num_contestants == (num_districts + 1) / 2) {
            int sum = 0;
            for (int x = 0; x < num_districts; x += 2) {
                sum += population[x];
            }
            cout << sum << endl;
        } else {
            cout << calcOpt(num_districts, num_contestants, population) << endl;
        }
    }   
}
