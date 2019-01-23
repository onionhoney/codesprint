//
//  main.cpp
//  AimBot
//
//  Created by Grant Schulte on 5/20/18.
//  Copyright © 2018 grantschulte. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    // Get the number of test cases
    int numTestCases = 0;
    std::cin >> numTestCases;
    
    // For each test case, solve the problem
    for (int testCase = 0; testCase < numTestCases; ++testCase) {
        
        // Store the result here after going through all shots...
        int result = 0;
        
        // Get: number of shots fired AND number of consecutive shots required before aim updates
        int shotsFired = 0;
        int consecutiveShotsReq = 0;
        std::cin >> shotsFired;
        std::cin >> consecutiveShotsReq;
        std::cin.get();  // Remove newline character
        
        // Get: string of shots
        std::string shotsList;
        std::getline(std::cin, shotsList);
        if (shotsList.size() < 3) {
            std::cout << 0 << std::endl;
            continue;
        }
        
        // Go through shots, update aim each consecutive k shots
        int consecutiveCount = 0;
        char currentLetter = shotsList[0];
        for (size_t i = 0; i < shotsFired; ++i) {
            if (shotsList[i] == currentLetter) {
                ++consecutiveCount;
                if (consecutiveCount >= 3) {
                    if (currentLetter == 'L') {
                        ++result;
                        consecutiveCount = 0;  // Reset consecutive count to wait for another consecutive 3 left misses
                    } else if (currentLetter == 'R') {
                        --result;
                        consecutiveCount = 0;  // Reset consecutive count to wait for another consecutive 3 right misses
                    }  // If hit... don't need to update
                }
            } else {
                consecutiveCount = 1;
                currentLetter = shotsList[i];
            }
        }
        
        std::cout << result << std::endl;
        
    }
    
    return 0;
}
