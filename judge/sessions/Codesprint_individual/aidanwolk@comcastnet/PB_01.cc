#include <iostream>
using namespace std;

int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++) {
        // each test case
        int length, width, numLines;
        cin >> length; // horizontal
        cin >> width;  // vertical
        cin >> numLines;
        int horLines = 0;
        int verLines = 0;
        for (int j = 0; j < numLines; j++) {
            int x1, y1, x2, y2;
            cin >> x1;
            cin >> y1;
            cin >> x2;
            cin >> y2;
            if (x1 == x2) {
                // vertical
                verLines++;
            } else {
                horLines++;
            }
        }
        cout << (horLines+1)*(verLines+1) << endl;
    }
}
