#include <iostream>
#include <algorithm>

using namespace std;

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int main(int argc, const char * argv[]) {
    int z;
    cin >> z;
    for (int y = 0; y < z; y++) {
        int n, t, p;
        cin >> n >> t >> p;
        int a[1000];
        int b[1000];
        int atotal = 0;
        int btotal = 0;
        for (int i = 0; i < t; i++) {
            cin >> a[i];
            atotal += a[i];
        }
        for (int i = 0; i < p; i++) {
            cin >> b[i];
            btotal += b[i];
        }
        if (atotal < n) {
            n = atotal;
        }
        if (btotal < n) {
            n = btotal;
        }
        int maxA = a[0];
        int maxAIndex = 0;
        int maxB = b[0];
        int maxBIndex = 0;
        int minA = a[t-1];
        int minAIndex = t-1;
        int minB = b[p-1];
        int minBIndex = p-1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sort(a, a+t);
            reverse(a, a+t);
            sort(b, b+p);
            reverse(b, b+p);
            minAIndex = t-1;
            minBIndex = p-1;
            while(a[minAIndex] <= 0) {
                minAIndex--;
            }
            while(b[minBIndex] <= 0) {
                minBIndex--;
            }
            maxA = a[0];
            /*for (int j = 1; j <= min(maxAIndex + 1, t-1); j++) {
             if (a[j] > a[0]) {
             maxA = a[j];
             maxAIndex = j;
             }
             }*/
            maxB = b[0];
            /*for (int j = 1; j <= min(maxBIndex + 1, p-1); j++) {
             if (b[j] > b[0]) {
             maxB = b[j];
             maxBIndex = j;
             }
             }*/
            
            minA = a[minAIndex];
            minB = a[minBIndex];
            
            if (maxA > maxB) {
                sum += maxA;
                a[maxAIndex]--;
                b[minBIndex]--;
            } else if (maxA < maxB) {
                sum += maxB;
                b[maxBIndex]--;
                a[minAIndex]--;
            } else {
                if (a[minAIndex] < maxA) {
                    sum += maxB;
                    b[maxBIndex]--;
                    a[minAIndex]--;
                } else {
                    sum += maxA;
                    a[maxAIndex]--;
                    b[minBIndex]--;
                }
            }
        }
        cout << sum << endl;
    }
}
