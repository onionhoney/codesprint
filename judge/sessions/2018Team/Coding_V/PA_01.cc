#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

int calibrate(string s, int length, int n);

int main()
{
        int numCases;
        cin >> numCases;

        for (int i = 0; i < numCases; i++)
        {
                int numShots;
                cin >> numShots;

                int k; // Calibration threshold
                cin >> k;

                cin.ignore(9999, '\n');

                string shots;
                getline(cin, shots);

                int calibration = calibrate(shots, numShots, k);

                cout << calibration << endl;
        }

        return 0;
}

int calibrate(string s, int length, int k)
{
    int numR = 0;
    int numL = 0;
    int calibratedAim = 0;

    for (int i = 0; i < length; i++)
    {
        if (s[i] == 'H')
        {
            numL = 0;
            numR = 0;
        }
        else if (s[i] == 'L')
        {
            numL += 1;
            numR = 0;
            if (numL == k)
                calibratedAim += 1;
        }
        else if (s[i] == 'R')
        {
            numR += 1;
            numL = 0;
            if (numR == k)
                calibratedAim -= 1;
        }
    }

    return calibratedAim;
}