#include <iostream>
using namespace std;
struct  Do {
	int l;
	int r;
	char c;
};
char check(int ind, Do list[], int n) {
	for (int i = n - 1; i >= 0; i--) {
		if (ind >= list[i].l && ind <= list[i].r)
			return list[i].c;
	}
	return 'a';
}
int main() {
	int n;
	cin >> n;
	Do* list = new Do[n];
	for (int i = 0; i < n; i++) {
		cin >> list[i].l >> list[i].r >> list[i].c;
	}
	int i0, i1, i2, i3;
	cin >> i0 >> i1 >> i2 >> i3;
	cout << check(i0, list, n) << " " << check(i1, list, n) << " " << check(i2, list, n) << " " << check(i3, list, n) << " " << endl;
	delete[] list;
}