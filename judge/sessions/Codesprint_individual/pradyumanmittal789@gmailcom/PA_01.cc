//  main.cpp
//  Problem 1
//
//  Created by Pradyuman Mittal on 1/28/17.
//  Copyright © 2017 Pradyuman Mittal. All rights reserved.

#include <iostream>
using namespace std;

int main()
{
    int t;
    do
    {
        cin >> t;
    }
    while (t < 0 || t > 100);
    for (int i = 0; i < t; i++)
    {
        int p, n;
        do
        {
            cin >> p;
            cin >> n;
        }
        while (p < 1 || p > 1000 || n < 1 || n > 50000);
        int n_i, b_i;
        int total;
        int numOfFlowers = 0;
        for (int i = 0; i < p; i++)
        {
            cin >> b_i;
            cin >> n_i;
            numOfFlowers += n_i;
            if (numOfFlowers <= n)
                total += b_i * n_i;
        }
        cout << total << endl;
    }
}
