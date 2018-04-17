//
//  main.cpp
//  CodeSprintA
//
//  Created by Neel Manthani on 1/28/17.
//  Copyright © 2017 Neel Manthani. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int testCases;
    int numTypes;
    int batt;
    int pts = 1000;
    int num;
    int totalPts;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        cin >> numTypes;
        cin >> batt;
        totalPts = 0;
        for (int j = 0; j != numTypes; j++)
        {
            if (batt == 0)
                break;
            cin >> pts;
            cin >> num;
            if (num > batt)
            {
                totalPts += batt * pts;
                batt = 0;
            }
            else
            {
                totalPts += num * pts;
                batt -= num;
            }
        }
        cout << endl;
        cout << totalPts;
    }
}
