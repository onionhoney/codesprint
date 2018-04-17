//
//  Problem2.cpp
//  CodeSprint
//
//  Created by Ritesh Pendekanti on 1/28/17.
//  Copyright © 2017 Ritesh Pendekanti. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        int horCount =0;
        int verCount =0;
        int total = 0 ;
        int hor;
        int ver;
        cin >> hor;
        cin >> ver;
        int tLines;
        cin >> tLines;
        for(int i = 0; i < tLines; i++)
        {
            int x1, x2, y1, y2;
            cin >> x1;
            cin >> y1;
            cin >> x2;
            cin >> y2;
            if(x1 == x2 && x1 == hor)
            {
                horCount ++;
            }
            if (y1 == y2 && y1 == ver)
            {
                verCount ++;
            }
            if( x1 == x2 && x1 == hor && verCount > 0)
            {
                total++;
            }
            if( y1 == y2 && y1 == hor && horCount > 0)
            {
                total++;
            }
            
        }
        total = total + (horCount + verCount);
        cout << total;
    }
}
