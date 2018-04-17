#include <iostream>
using namespace std;

struct Flower {
    int beauty;
    int numCanDraw;
};

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        // Each test case
        int numFlowerTypes, numFlowersCanDraw;
        cin >> numFlowerTypes;
        cin >> numFlowersCanDraw;
        Flower *flowers = new Flower[numFlowerTypes];
        for (int j = 0; j < numFlowerTypes; j++) {
            cin >> flowers[j].beauty;
            cin >> flowers[j].numCanDraw;
        }
        int numDrawn = 0;
        int totalBeauty = 0;
        int flowerIndex = 0;
        while (numDrawn < numFlowersCanDraw && flowerIndex < numFlowerTypes) {
            if (flowers[flowerIndex].numCanDraw > 0) {
                totalBeauty += flowers[flowerIndex].beauty;
                flowers[flowerIndex].numCanDraw--;
                numDrawn++;
            } else {
                flowerIndex++;
            }
        }
        cout << totalBeauty << endl;
        delete [] flowers;
    }
}
