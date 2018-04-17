#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	string* str = new string[1000001];
	for (int i = 0;i < 1000000;i++) {
		*(str + i) = 'a';
	}
	*(str + 1000000) = '\n';
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int l;
		int r;
		cin >> l;
		cin >> r;
		char c;
		cin >> c;
		for (int q = l; q < r; l++) {
			*(str + l) = c;
		}
	}
	int i1;
	int i2;
	int i3;
	int i4;
	cin >> i1;
	cin >> i2;
	cin >> i3;
	cin >> i4;
	string ret = "";
	ret += *(str + i1);
	ret += " ";
	ret += *(str + i2);
	ret += " ";
	ret += *(str + i3);
	ret += " ";
	ret += *(str + i4);
	ret += " ";
	cout << ret;
}