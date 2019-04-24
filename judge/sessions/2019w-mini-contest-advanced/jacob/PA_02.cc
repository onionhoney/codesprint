#include <iostream>
#include <algorithm>

using namespace std;

struct Coord {
    int row;
    int space;
    bool operator< (const Coord& c) const {
        return (c.row < row || (c.row == row && c.space < space));
    }
};


int main () {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n, m, s, b;
        cin >> n >> m >> s >> b;

        vector<Coord> blackholes;
        for (int i = 0; i < b; i++) {
            Coord c;
            cin >> c.row >> c.space;
            blackholes.push_back(c);
        }

        sort(blackholes.begin(), blackholes.end());

        int width = 2*m+1;
        double probabilities[width + 2];
        for (int i = 0; i <= width+1; i++) {
            probabilities[i] = 0;
        }

        probabilities[s] = 1;

        vector<Coord>::iterator bh = blackholes.begin();
        vector<Coord>::iterator end = blackholes.end();
        bool noMoreBlackHoles = false;

        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0) {
                // small row to big row
                for (int j = 2; j < width; j += 2) {
                    probabilities[j-1] += 0.5 * (probabilities[j]);
                    probabilities[j+1] += 0.5 * (probabilities[j]);
                    probabilities[j] = 0; // clean out the small row
                }
            } else {
                // big row to small row
                probabilities[2] += probabilities[1];

                probabilities[1] = 0;

                probabilities[width - 1] += probabilities[width];

                probabilities[width] = 0;

                for (int j = 3; j < width; j += 2) {
                    probabilities[j-1] += 0.5 * (probabilities[j]);
                    probabilities[j+1] += 0.5 * (probabilities[j]);
                    probabilities[j] = 0;// clean it out
                }
            }

            while (bh != end && (*bh).row == i) {
                probabilities[(*bh).space] = 0;
                bh++;
            }

            for (int j = 1; j <= width; j++) { // parity agnostic
                cout << probabilities[j] << " ";
            }
            cout << endl;
        }

        double maxprob = 0;

        for (int j = 1; j <= width; j++) { // parity agnostic
            cout << probabilities[j] << " ";
            if (probabilities[j] > maxprob) {
                maxprob = probabilities[j];
            }
        }

        cout << endl;

        if (maxprob == 0) {
            cout << -1 << endl;
            continue;
        }

        for (int j = 1; j <= width; j++) {
            if (probabilities[j] == maxprob) {
                cout << j << " ";
            }
        }
        cout << endl;

    }
    return 0;
}