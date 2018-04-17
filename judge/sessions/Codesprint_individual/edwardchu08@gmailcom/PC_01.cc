//
//  main.cpp
//  Problem3
//
//  Created by Edward Chu on 28/1/2017.
//  Copyright © 2017 Puffins. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    int testCases;
    cin >> testCases;
    
    for(int tests = 0; tests < testCases; tests++){
        int rows;
        cin >> rows;
        
        int cols;
        cin >> cols;
        
        
        int currRow;
        cin >> currRow;
        currRow--;
        
        int currCol;
        cin >> currCol;
        currCol--;
        
        char** map = new char*[rows];
        for(int i = 0; i < rows; i++){
            map[i] = new char[cols];
        }
        
        int stepsToTake = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                cin >> map[i][j];
                if(map[i][j] == '#')
                    stepsToTake++;
            }
        }
        
        /*
        //Print map;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                cout << map[i][j];
            }
            cout << endl;
        }
         */
        
        string route;
        while(stepsToTake > 0){
            
            if(currRow-1 >= 0 && map[currRow-1][currCol] == '#'){
                route += 'U';
                currRow--;
                map[currRow][currCol] = '.';
                stepsToTake--;
            }
            
            if(currRow+1 < rows  && map[currRow+1][currCol] == '#'){
                route += 'D';
                currRow++;
                map[currRow][currCol] = '.';
                stepsToTake--;
            }
            
            if(currCol+1 < cols && map[currRow][currCol+1] == '#'){
                route += 'R';
                currCol++;
                map[currRow][currCol] = '.';
                stepsToTake--;
            }
            
            if(currCol-1 >= 0 && map[currRow][currCol-1] == '#'){
                route += 'L';
                currCol--;
                map[currRow][currCol] = '.';
                stepsToTake--;
            }
        }
        
        cout << route << endl;
    }
    return 0;
}
