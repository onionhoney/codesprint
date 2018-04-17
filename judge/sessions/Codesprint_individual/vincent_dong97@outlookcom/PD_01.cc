#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int left[n];
    int right[n];
    char character[n];
    for (int i = 0; i < n; i++)
        cin >> left[i] >> right[i] >> character[i];
    int num[4];
    char result[4];
    cin >> num[0] >> num[1] >> num[2] >> num[3];
    bool need[4];
    for (int i = 0; i < 4; i++)
        need[i] = true;
    for (int i = n - 1; i >= 0; i--) {
        int l = left[i], r = right[i], c = character[i];
        for (int j = 0; j < 4; j++) {
            if (need[j] && num[j] >= l && num[j] <= r) {
                result[j] = c;
                need[j] = false;
            }
        }
    }
    for (int i = 0; i < 4; i++)
        if (need[i])
            cout << "a ";
        else
            cout << result[i] << " ";
    cout << endl;

}
