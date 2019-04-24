#include <iostream>
using namespace std;

int grid[100][100];

int main(int argc, const char * argv[]) {
    int t;
    int n;
    int draw;
    int x1, y1, x2, y2;
    cin >> t;
    for (int z = 0; z < t; z++) {
        int count = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> draw;
            cin >> x1 >> y1 >> x2 >> y2;
            for (int x = x1; x < x2; x++) {
                for (int y = y1; y < y2; y++) {
                    grid[x][y] = draw;
                }
            }
        }
        for (int x = 0; x < 100; x++) {
            for (int y = 0; y < 100; y++) {
                count += grid[x][y];
                grid[x][y] = 0;
            }
        }
        cout << count << endl;
    }
    return 0;
}
