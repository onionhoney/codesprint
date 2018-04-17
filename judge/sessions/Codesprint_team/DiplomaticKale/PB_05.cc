#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char maxi[1000][1000];
int around(int a, int b) {
	int count = 0;
	if (maxi[a - 1][b] == '*')count++;
	if (maxi[a - 1][b + 1] == '*')count++;
	if (maxi[a - 1][b - 1] == '*')count++;
	if (maxi[a + 1][b] == '*')count++;
	if (maxi[a + 1][b - 1] == '*')count++;
	if (maxi[a + 1][b + 1] == '*')count++;
	if (maxi[a][b + 1] == '*')count++;
	if (maxi[a][b - 1] == '*')count++;
	return count;
}
int main() {
	int number;
	scanf("%d", &number);
	while (number--) {
		int count = 0;
		memset(maxi, 0, sizeof(maxi));
		int r, c;
		scanf("%d %d", &r, &c);
		int kase;
		scanf("%d", &kase);
		while (kase--) {
			int rc, cc;
			scanf("%d %d", &rc, &cc);
			maxi[rc][cc] = '*';
		}
		for (int a = 1; a <= r; a++) {
			for (int b = 1; b <= c; b++) {
				if (maxi[a][b] == '*')continue;
				count += around(a, b);
			}
		}
		printf("%d\n", count);
	}
	return 0;
}