//
//  main.cpp
//  ProblemB
//
//  Created by Edward Chu on 28/1/2017.
//  Copyright © 2017 Puffins. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    int testCases;
    cin >> testCases;
    
    for(int test = 0; test < testCases; test++){
        int rows;
        cin >> rows;
        
        int cols;
        cin >> cols;
        
        int** map = new int*[rows];
        for(int i = 0; i < rows; i++){
            map[i] = new int[cols];
        }
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                map[i][j] = 0;
            }
        }
        
        int numToothpaste;
        cin >> numToothpaste;
        
        for(int i = 0; i < numToothpaste; i++){
            int posR, posC;
            cin >> posR >> posC;
            
            map[posR-1][posC-1] = 1;
        }
        /*
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                cerr << map[i][j];
            }
            
            cerr << endl;
        }
        */
        int candies = 0;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(map[i][j] != 1){
                    if(i-1 >= 0){
                        candies += map[i-1][j];
                    }
                    if(i+1 < rows){
                        candies += map[i+1][j];
                    }
                    if(j+1 < cols){
                        candies += map[i][j+1];
                    }
                    if(j-1 >= 0){
                        candies += map[i][j-1];
                    }
                    
                    if(i-1 >= 0 && j+1 < cols)
                        candies += map[i-1][j+1];
                    
                    if(i-1 >= 0 && j-1 >= 0){
                        candies += map[i-1][j-1];
                    }
                    
                    if(i+1< rows && j+1 < cols){
                        candies += map[i+1][j+1];
                    }
                    
                    if(i+1 < rows && j-1 >= 0){
                        candies += map[i+1][j-1];
                    }
                }
            }
        }
        
        cout << candies << endl;
        
    }
    
    return 0;
}
