#include <iostream>
#include <string>
using namespace std;

int main() {
	int number;
	scanf("%d", &number);
	while (number--) {
		int sum = 0;
		int t, n;
		scanf("%d %d", &t, &n);
		while (t--) {
			int ft, fn;
			scanf("%d %d", &ft, &fn);
			while (fn--&&n) {
				sum += ft;
				n--;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}