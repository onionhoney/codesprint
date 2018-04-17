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
        cin >> x1 >> y1 >> x2 >> y2;
        
        bool firstlinehor;
        if(x1 == x2)
            firstlinehor = false;
        else
            firstlinehor = true;
        
        int numDis = 2;
        
        for(int i = 1; i < numLines; i++){
            cin >> x1 >> y1 >> x2 >> y2;
            if(x1 == x2 && firstlinehor){
                numDis *= 2;
            }
            else if(y1 == y2 && firstlinehor){
                numDis += 2;
            }
            else if(x1 == x2 && !firstlinehor){
                numDis += 2;
            }
            else if(y1 == y2 && !firstlinehor){
                numDis *= 2;
            }
        }
        
        cout << numDis << endl;
        
    }
    
    return 0;
}
