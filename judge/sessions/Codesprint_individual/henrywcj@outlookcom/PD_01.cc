#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	int n;
	cin >> n;
	char ch[1000000];
	for (int i = 0; i < 1000000; i++)
		ch[i] = 'a';
	for (int i = 0; i < n; i++)
	{
		int l, m;
		char chs;
		cin >> l >> m;
		cin.ignore(1);
		cin >> chs;
		for (int j = l; j <= m; j++)
			ch[j] = chs;
	}
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << ch[a] << ' ' << ch[b] << ' '<< ch[c] << ' ' << ch[d];
	cout << endl;
}