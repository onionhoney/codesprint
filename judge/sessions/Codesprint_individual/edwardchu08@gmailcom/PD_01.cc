//
//  main.cpp
//  Problem4
//
//  Created by Edward Chu on 28/1/2017.
//  Copyright © 2017 Puffins. All rights reserved.
//

#include <iostream>


using namespace std;
int main() {
    
    
    int numInstruct;
    cin >> numInstruct;
    
    int* starts = new int[numInstruct];
    int* ends = new int[numInstruct];
    char* letters = new char[numInstruct];
    
    
    for(int i = 0; i < numInstruct; i++){
        cin >> starts[i] >> ends[i] >> letters[i];
    }
    
    
    
    
    for(int i = 0; i < 4; i++){
        char temp = 'a';
        int loc;
        
        cin >> loc;
        
        for(int j = 0; j < numInstruct; j++){
            if(loc >= starts[j] && loc <= ends[j]){
                temp = letters[j];
            }
        }
        
        cout << temp << ' ';
    }
    cout << endl;
    return 0;
}
