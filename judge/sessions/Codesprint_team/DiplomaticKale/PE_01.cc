#include <iostream>
#include <cmath>


using namespace std;

int countpoints(int r, double shift);

int main() {
    int t;
    cin >> t;
    int results[t];
    for (int i = 0; i < t; i++) {
        int r;
        cin >> r;
        int maxcount = countpoints(r, 0);
        for (int j = 3; j < r; j++) {   // right shift along the line y = j to the next point
            double x = sqrt(r * r - j * j); //  the circle passes (x, j)
            if (x != ceil(x)) {
                double shift = ceil(x) - x;
                int points = countpoints(r, shift);
                if (points > maxcount)
                    maxcount = points;
            }
        }
        
        results[i] = maxcount;
    }
    
    for (int i = 0; i < t; i++)
        cout << results[i] << endl;


}

int countpoints(int r, double shift) {
    int left = (shift == 0) ? -r : -r + 1;
    int right = r;
    int count = 0;
    for (int i = left; i <= right; i++) {
        int h = (int) sqrt(r * r - (i-shift) * (i-shift));
        count += 2 * h + 1;
    }
    return count;
}
