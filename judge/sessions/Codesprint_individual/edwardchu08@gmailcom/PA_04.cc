//
//  main.cpp
//  Problem1
//
//  Created by Edward Chu on 28/1/2017.
//  Copyright © 2017 Puffins. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numTestCases;
    
    
    cin >> numTestCases;
    
    for(int i = 0; i < numTestCases; i++){
        int numFlowers;
        int beauty = 0;
        cin >> numFlowers;
        
        int battery;
        cin >> battery;
        
        int* numDraw = new int[numFlowers];
        int* value = new int [numFlowers];
        
        int* ptr2 = numDraw;
        
        for(int* ptr1 = value; ptr1 < value+numFlowers; ptr1++, ptr2++){
            int temp;
            cin >> temp;
            //cerr << temp;
            *ptr1 = temp;
            
            cin >> temp;
            *ptr2 = temp;
        }
        //cerr << endl;
        /*
        //Print
        for(int i = 0; i < numFlowers; i++){
            cerr << value[i] << endl;
            cerr << numDraw[i] << endl;
        }
        cerr << "ptin" << endl;
        */
        while(battery > 0 && numFlowers > 0){
            
            for(int j = 0; j < numFlowers; j++){
                if(numDraw[j] == 0){
                    numDraw[j] = numDraw[numFlowers-1];
                    value[j] = value[numFlowers-1];
                    numFlowers--;
                    j--;
                }
            }
            
            int maxPos = 0;
            int max = value[0];
            for(int j = 0; j < numFlowers; j++){
                if(value[j] > max){
                    maxPos = j;
                    max = value[j];
                }
                
            }
            
            while(numDraw[maxPos] != 0){
                
                beauty += value[maxPos];
                numDraw[maxPos]--;
                battery --;
                if(battery == 0)
                    break;
                
            }
            
            if(battery == 0)
                break;
            
            for(int j = 0; j < numFlowers; j++){
                if(numDraw[j] == 0){
                    numDraw[j] = numDraw[numFlowers-1];
                    value[j] = value[numFlowers-1];
                    numFlowers--;
                    j--;
                }
            }
            
            /*
            //Print
            for(int i = 0; i < numFlowers; i++){
                cerr << value[i] << endl;
                cerr << numDraw[i] << endl;
            }
            cerr << "ptin" << endl;
             */
            
        }
        
        delete [] numDraw;
        delete [] value;
        
        cout << beauty << endl;
    }
    
    return 0;
}
