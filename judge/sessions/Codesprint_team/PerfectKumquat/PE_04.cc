//
//  main.cpp
//  ProblemE
//
//  Created by Edward Chu on 28/1/2017.
//  Copyright © 2017 Puffins. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    
    int numCases;
    cin >> numCases;
    
    for(int tests = 0; tests < numCases; tests++){
        int radius;
        cin >> radius;
        
        //cout << floor(3.141592*radius*radius+1) << endl;
        
        
        int max = 0;
        
        
        
        
        for(double offset = 0; offset < 1; offset += 0.05){
            int countDots = 0;
            for(double i = -radius; i <= radius; i++){
                for(double j = -radius; j <= radius; j++){
                    if(sqrt(((i-offset)*(i-offset))+(j*j)) <= radius){
                        countDots++;
                        //cerr << i << ' ' << j << endl;
                    }
                }
            }
            
            if(countDots > max)
                max = countDots;
        }
        
        cout << max << endl;
        
        
    }
    
    return 0;
}
