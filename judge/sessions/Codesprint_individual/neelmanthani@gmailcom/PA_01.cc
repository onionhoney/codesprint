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
    int prevPts = 0;
    cin >> testCases;
    if (testCases > 100)
        testCases = 100;
    cin >> numTypes;
    if (numTypes > 1000)
        numTypes = 1000;
    cin >> batt;
    if (batt > 50000)
        batt = 50000;
    for (int i = 0; i < testCases; i++)
    {
        totalPts = 0;
        for (; pts > prevPts; prevPts = pts)
    {
        cin >> pts;
        cin >> num;
        if (num <= numTypes)
            totalPts += num * pts;
        else
            totalPts += numTypes * pts;
    }
        cout << totalPts << endl;
    }
}
