#include <iostream>
using namespace std;

int numWaysSec(int numSteps) {
    if (numSteps <= 3) {
        if (numSteps == 1)
            return 1;
        else if (numSteps == 2)
            return 2;
        else if (numSteps == 3)
            return 4;
    }
    return 4*numWaysSec(numSteps - 3) + 2*numWaysSec(numSteps - 2) + numWaysSec(numSteps - 1);
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
