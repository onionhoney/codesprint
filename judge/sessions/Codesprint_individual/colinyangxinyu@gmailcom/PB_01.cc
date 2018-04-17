
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    int numtests;
    cin >> numtests;
    for (int i = 0; i < numtests; i++) {
        int m, n, k;
        cin >> m >> n >> k;

        int row = 1, col = 1;
        for (int j = 0; j < k; j++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            if (x1 == x2) row++;
            else if (y1 == y2) col++;
        }

        cout << row*col << endl;
    }

    return 0;
}
