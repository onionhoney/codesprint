#include <iostream>
using namespace std;
int main() {
	int cases;
	cin >> cases;
	for (int cas = 0; cas < cases; cas++) {
		int n;
		cin >> n;
		int* arr = new int[n];
		int max = -1;
		for (int i = 0; i < n; i++) {
			int j;
			cin >> j;
			arr[i] = j;
			if (j > max)
				max = j;
		}
		int* fib = new int[max+5];
		fib[0] = 1;
		fib[1] = 1;
		fib[2] = 2;
		for (int i = 3; i < max + 5; i++) {
			fib[i] = fib[i - 1] + fib[i - 2] + fib[i - 3];
		}
		int ans = 1;
		for (int i = 0; i < n; i++) {
			ans *= fib[arr[i]];
		}
		cout << ans << endl;
	}
}