//
//  SmallbergsDilemma.cpp
//  CodeSpring
//
//  Created by Grant Schulte on 5/20/18.
//  Copyright © 2018 grantschulte. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main() {
    
    int numTestCases = 0;
    std::cin >> numTestCases;
    
    for (int i = 0; i < numTestCases; ++i) {
        
        // Get test case input
        int maxNumJumps = 0;
        int numOptions31 = 0;
        int numOptions32 = 0;
        std::cin >> maxNumJumps;
        std::cin >> numOptions31;
        std::cin >> numOptions32;
        
        std::vector<int> classSizes31(numOptions31);
        std::vector<int> classSizes32(numOptions32);
        for (int i = 0, option = 0; i < numOptions31; ++i) {
            std::cin >> option;
            classSizes31[i] = option;
        }
        for (int i = 0, option = 0; i < numOptions32; ++i) {
            std::cin >> option;
            classSizes32[i] = option;
        }
        
        /*
        // Set up hash tables to store complements of each number
        std::unordered_map<int, int> complement31(numOptions31);
        std::unordered_map<int, int> complement32(numOptions32);
        
        // Get complements of each class size from both CS 31 and CS 32
        for (int x : classSizes31) {
            complement31[maxNumJumps - x] = x; // what's left over after choosing 31 class?
        }
        for (int x : classSizes32) {
            complement32[maxNumJumps - x] = x;
        }
        
        // For each class in 32, select the one that uses all of Smallberg's jumps
        for (int i = 0; i < numOptions31; ++i) {
            int val31Comp = maxNumJumps - classSizes31[i];
            auto it = complement32.find(val31Comp);
            if (it != complement32.end()) {
                std::cout << (complement32[val31Comp] + classSizes31[i]) << std::endl;
                break;
            }
        }
        std::cout << "DID NOT FIND" << std::endl;
         */
        int max = 0;
        for (int i = 0; i < numOptions31; ++i) {
            for (int j = 0; j < numOptions32; ++j) {
                int numStudents = classSizes31[i] + classSizes32[j];
                int jumpsLeft = maxNumJumps - numStudents;
                if (jumpsLeft >= 0) {
                    if (numStudents > max) {
                        max = numStudents;
                    }
                }
            }
        }
        
        std::cout << max << std::endl;
        
    }
    
    
    return 0;
}


