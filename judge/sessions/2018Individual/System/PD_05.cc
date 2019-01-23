#include <iostream>
#include <math.h>

using namespace std;

int max (int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main(int argc, const char * argv[]) {
    int floor[100001];
    int orderfloor[100001];
    int t;
    cin >> t;
    int a, b, c, f, p;
    int tmp;
    for (int z = 0; z < t; z++) {
        cin >> a >> b >> c >> f >> p;
        for (int i = 1; i <= f; i++) {
            floor[i] = 0;
        }
        for (int i = 0; i < p; i++) {
            cin >> tmp;
            floor[tmp] = 1;
        }
        orderfloor[0] = 1;
        int j = 0;
        for (int i = 1; i <= f; i++) {
            if (floor[i] > 0) {
                j++;
                orderfloor[j] = i;
            }
        }
        int min = (orderfloor[j] - 1) * c; // everyone climbs the stairs
        for (int i = 0; i < j; i++) {
            // first i floors climb the stairs, j-i floors take the elevator
            if (max((orderfloor[i]-1)*c, (orderfloor[j]-1)*a + (j-i-1)*b) < min) {
                min = max((orderfloor[i]-1)*c, (orderfloor[j]-1)*a + (j-i-1)*b);
            }
        }
        cout << min << endl;
    }
}
