#include <iostream>

using namespace std;

int findways(int n);

int main() {
    int t;
    cin >> t;
    int results[t];
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int totalways = 1;
        for (int j = 0; j < n; j++) {
            int steps;
            cin >> steps;
            int ways = findways(steps);
            totalways = (totalways * ways) % 10007;
        }
        results[i] = totalways;
    }
    
    for (int i = 0; i < t; i++)
        cout << results[i] << endl;
    
}

int findways(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    int one = findways(n - 1);
    int two = findways(n - 2);
    int three = findways(n -3);
    
    return (one + two + three) % 10007;
}
