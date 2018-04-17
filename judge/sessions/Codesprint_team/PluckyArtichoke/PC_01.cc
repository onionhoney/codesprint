#include <iostream>
using namespace std;

struct TrafficLight {
    int loc;
    int period;
};

bool lightIsGreen(int period, int time) {
    int numPeriods = time / period;
    return numPeriods % 2 == 0;
}

int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++) {
        // each test case
        int roadLength, numLights, speedLimit;
        cin >> roadLength;
        cin >> numLights;
        cin >> speedLimit;
        TrafficLight* lights = new TrafficLight[numLights];
        for (int j = 0; j < numLights; j++) {
            cin >> lights[j].loc;
            cin >> lights[j].period;
        }
        int speed;
        for (speed = speedLimit; speed > 0; speed--) {
            double time = 0;
            double pos = 0;
            bool failed = false;
            for (int j = 0; j < numLights; j++) {
                time += (lights[j].loc - pos) / speed;
                if (!lightIsGreen(lights[j].period, time)) {
                    failed = true;
                    break;
                }
                pos = lights[j].loc;
            }
            if (!failed) {
                cout << speed << endl;
                break;
            }
        }
        if (speed == 0)
            cout << -1 << endl;
        delete [] lights;
    }
}
