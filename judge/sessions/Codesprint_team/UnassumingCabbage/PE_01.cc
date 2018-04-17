#include <iostream>
#include <cassert>
#include <string.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int getInput(string s, int& x) {
    int num = 0;
    while (isdigit(s[x])) {
        num = num*10 + s[x] - '0';
        x++;
    }
    x ++;
    return num;
}
double dist(int x, int y, int a, int b) {
    return sqrt((x-a)*(x-a) + (y-b)*(y-b));
}
struct Light {
    int loc;
    int per;
};

int main() {
    int arr[] = {1, 5, 13, 29, 49, 81, 113, 149, 197, 253, 317, 377, 441, 529, 613, 709, 797, 901, 1009, 1129, 1257, 1373, 1517, 1653, 1793, 1961, 2121, 2289, 2453, 2629, 2821, 3001, 3209, 3409, 3625, 3853, 4053, 4293, 4513, 4777, 5025, 5261, 5525, 5789, 6077, 6361, 6625};
    int n = 45;
    int t = 0, x = 0;
    string input;
    getline(cin, input);
    t = getInput(input, x);
    for (int test = 0; test < t; test ++) {
        int r;
        cin >> r;
        cout << arr[r] << endl;
//        double answer = 3.14159265358979323846 * r * r;
//        int a = answer;
//        cout << answer << " " << a << endl;
    }
}
