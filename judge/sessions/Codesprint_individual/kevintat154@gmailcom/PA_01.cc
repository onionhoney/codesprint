//
//  main.cpp
//  whyisthisnotinpython
//
//  Created by Kevin Tat on 1/28/17.
//  Copyright © 2017 Kevin Tat. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <sstream>
#include <numeric>


using namespace std;

int reader() {
    map<int, int> everything;
    int t = 0;
    cout << "Enter the number of test cases: ";
    cin >> t;
    int sum = 0;
    
    for (int i = 0; i < t; i++){
        int drawn = 0;
        int x;
        int y;
        cout << "Enter test case " << "i " << " ";
        cin >> x >> y;
        
        for (int j = 0; j < x; j++){
            int b = 0;
            int n = 0;
            
            cout << "Enter each b and n ";;
            cin >> b >> n;
            
            for (int k = 0; k < n; k++){
                drawn += 1;
                if (drawn == y){
                    return sum;
                }
                else if (drawn < y){
                    sum += b;
                }
            }
            
        }
    }
    cout << sum;
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    reader();
    
    
    return 0;
}
