#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > max) max = arr[i];
    }
    
    int *fib = new int[max];
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < max; i++) {
        fib[i] = (fib[i-1] + fib[i-2])%100000007;
    }
    
    for (int i = 0; i < n; i++) {
        cout << fib[arr[i]-1] << endl;
    }
}
