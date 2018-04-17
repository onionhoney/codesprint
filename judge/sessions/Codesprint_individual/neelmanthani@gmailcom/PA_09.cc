//
//  main.cpp
//  CodeSprintB
//
//  Created by Neel Manthani on 1/28/17.
//  Copyright © 2017 Neel Manthani. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int v_lines = 0;
    int h_lines = 0;
    int testCases;
    int totalLines = 0;
    int districts = 1;
    int x, y, x1, x2, y1, y2;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        cin >> x;
        cin >> y;
        cin >> totalLines;
        
        for(int i = 0; i < totalLines; i++)
        {
            
            cin >> x1;
            cin >> y1;
            cin >> x2;
            cin >> y2;
            
            if (x1 - x2 != 0)
            {
                districts += 1 + v_lines;
                h_lines++;
            }
            else if (y1 - y2 != 0)
            {
                districts += 1 + h_lines;
                v_lines++;
            }
        }
        cout << districts << endl;
        districts = 1;
        v_lines = 0;
        h_lines = 0;
    }
}
