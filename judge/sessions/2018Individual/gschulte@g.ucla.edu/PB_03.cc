//
//  main.cpp
//  UCLATunneling
//
//  Created by Grant Schulte on 5/20/18.
//  Copyright © 2018 grantschulte. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    
    int numTestCases = 0;
    std::cin >> numTestCases;
    std::cin.get();
    
    int result[3] = { 0, 0, 0 };
    for (int i = 0; i < numTestCases; ++i) {
        for (int line = 0; line < 3; ++line) {
            for (int j = 0; j < 100; ++j) {
                int num = 0;
                std::cin >> num;
                std::cin.get();
                if (num == 1) {
                    result[line] = j;
                }
            }
        }
        std::cout << result[0] << ' ' << result[1] << ' ' << result[2] << std::endl;
    }
    
    return 0;
    
}
