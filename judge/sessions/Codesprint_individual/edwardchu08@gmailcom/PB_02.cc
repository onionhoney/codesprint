//
//  main.cpp
//  Problem2
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
        int hor;
        cin >> hor;
        
        int ver;
        cin >> ver;
        
        int numLines;
        cin >> numLines;
        
        int x1, y1, x2, y2;
        //cin >> x1 >> y1 >> x2 >> y2;
        
        bool firstlinehor;
        int numHor = 0;
        int numVer = 0;
        
        
        for(int i = 0; i < numLines; i++){
            cin >> x1 >> y1 >> x2 >> y2;
            
            
            if(x1 == x2){
                numVer++;
            }
            else if(y1 == y2){
                numHor++;
            }
            
        }
        
        cout << (numVer+1)*(numHor+1) << endl;
        
    }
    
    return 0;
}
