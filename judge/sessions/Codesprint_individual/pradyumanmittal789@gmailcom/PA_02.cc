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
    cin >> t;
    if (t > 100)
        t = 100;
    for (int i = 0; i < t; i++)
    {
        int p, n;
        cin >> p;
        if (p > 1000)
            p = 1000;
        cin >> n;
        if (n > 1000)
            n = 1000;
        int n_i, b_i;
        int total;
        int numOfFlowers = 0;
        for (int i = 0; i < p; i++)
        {
            cin >> b_i;
            if (b_i > 1000)
                b_i = 1000;
            cin >> n_i;
            if (n_i < 1)
                n_i = 1;
            if (numOfFlowers + n_i > n)
                n_i = n - numOfFlowers;
            numOfFlowers += n_i;
            if (numOfFlowers <= n)
                total += b_i * n_i;
        }
        cout << total << endl;
        total = 0;
    }
}

