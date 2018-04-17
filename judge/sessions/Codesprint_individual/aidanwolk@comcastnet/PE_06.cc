#include <iostream>
#include <map>
using namespace std;

unsigned long table[10000] = {0, 1, 2, 4};

unsigned long numWaysSec(int numSteps) {
    if (numSteps < 1000 && table[numSteps] != 0)
        return table[numSteps];
    if (numSteps <= 3) {
        if (numSteps == 1)
            return 1;
        else if (numSteps == 2)
            return 2;
        else if (numSteps == 3)
            return 4;
    }
    unsigned long result = numWaysSec(numSteps - 1) + numWaysSec(numSteps - 2) + numWaysSec(numSteps - 3);
    if (numSteps < 10000)
        table[numSteps] = result;
    return result;
}

int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++) {
        // each test case
        unsigned long numWays = 1;
        int numSections;
        cin >> numSections;
        for (int i = 0; i < numSections; i++) {
            int numSteps;
            cin >> numSteps;
            numWays *= numWaysSec(numSteps);
            numWays %= 10007;
        }
        cout << numWays << endl;
    }
}
