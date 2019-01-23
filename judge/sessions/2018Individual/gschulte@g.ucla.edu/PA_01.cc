//
//  main.cpp
//  CodeSpring
//
//  Created by Grant Schulte on 5/20/18.
//  Copyright © 2018 grantschulte. All rights reserved.
//

#include <iostream>
#include <vector>


unsigned long long fib_dp(int a);

unsigned long long fib_helper(int a, std::vector<unsigned long long>& memo);

int main(int argc, const char * argv[]) {
    
    int n = 0;
    std::cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int ithFib = 0;
        std::cin >> ithFib;
        unsigned long long result = fib_dp(ithFib);
        std::cout << result << std::endl;
    }
    
    return 0;
    
}


unsigned long long fib_dp(int a) {
    
    std::vector<unsigned long long> memo(a+1, -1);
    unsigned long long result = fib_helper(a, memo);
    
    return result % 100000007;
}


unsigned long long fib_helper(int a, std::vector<unsigned long long>& memo) {
    
    memo[1] = 1;
    memo[2] = 1;
    
    for (int i = 3; i <= a; ++i) {
        memo[i] = memo[i-1] + memo[i-2];
    }
    
    return memo[a];
    
}

















