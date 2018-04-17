//
//  Problem1.cpp
//  CodeSprint
//
//  Created by Ritesh Pendekanti on 1/28/17.
//  Copyright © 2017 Ritesh Pendekanti. All rights reserved.
//


#include <iostream>
using namespace std;

int main()
{
    int testCases;
    cin >> testCases;
    if (testCases >= 1 && testCases <= 100)
    {
    for(int i = 0; i < testCases; i++)
    {
        int total = 0;
        int p, n;
        cin >> p;
        cin >> n;
        int flowerCount = 0;
        for (int i = 0; i < p; i++)
        {
            int otherCount = 0;
            int bi, ni;
            cin >> bi;
            cin >> ni;
            while(flowerCount < n && otherCount < ni )
            {
                total = total + bi;
                flowerCount++;
                otherCount++;
            }
        }
        cout << total << endl;
    }
        
    }
}
