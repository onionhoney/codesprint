//
//  main.cpp
//  UCLATunneling
//
//  Created by Grant Schulte on 5/20/18.
//  Copyright © 2018 grantschulte. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int numTestCases = 0;
    std::cin >> numTestCases;
    
    for (int i = 0; i < numTestCases; ++i) {
        for (int line = 0; line < 3; ++line) {
            for (int j = 0; j < 100; ++j) {
                int num = 0;
                std::cin >> num;
                if (num == 1) {
                    std::cout << j << ' ';
                }
            }
        }
        std::cout << std::endl;
    }
    
}
