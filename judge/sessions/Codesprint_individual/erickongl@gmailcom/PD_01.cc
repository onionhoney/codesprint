#include <iostream>
#include <string>
using namespace std;

int main() {
	int n; // Instructions.
	cin >> n;

	char * str;
	str = new char[1000000];

	for (int i = 0; i < 1000000; i++)
	{
		str[i] = 'a';
	}

	for (int i = 0; i < n; i++)
	{
		int l, r;
		char c;
		cin >> l >> r >> c;

		for (int j = l; j < r + 1; j++)
		{
			str[i] = c;
		}
	}

	int i0, i1, i2, i3;
	cin >> i0 >> i1 >> i2 >> i3;

	cout << str[i0] << " " << str[i1] << " " << str[i2] << " " << str[i3] << " " << endl;

	delete[] str;
}

/*
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int t; // Test cases.
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int m, n;
		cin >> m >> n;

		int a, b;
		cin >> a >> b;

		char maze[101][101];

		for (int j = 0; j < m; j++)
		{
			string line;
			getline(cin, line);

			int len = line.length();

			for (int k = 0; k < len; k++)
			{
				maze[j][k] = line[k];
			}
		}

		// Start of path.

		string path = "";

		a--;
		b--;

		while (1) {
			// Go left.
			if (a > 0 && maze[a - 1][b] == '#')
			{
				maze[a][b] = '.';
				a--;
				path = path + 'L';
			}
			// Go right.
			else if (a < m - 1 && maze[a + 1][b] == '#')
			{
				maze[a][b] = '.';
				a++;
				path = path + 'R';
			}
			// Go up.
			else if (b > 0 && maze[a][b - 1] == '#')
			{
				maze[a][b] = '.';
				b--;
				path = path + 'U';
			}
			// Go down.
			else if (b < n - 1 && maze[a][b + 1] == '#')
			{
				maze[a][b] = '.';
				b++;
				path = path + 'D';
			}
			else
			{
				break;
			}
		}

		cout << path << endl;
	}
}
*/
/*
int numWays(int);

int main() {

	int * nums;
	nums = new int[1000001];

	nums[0] = 0;
	nums[1] = 1;
	nums[2] = 2;
	nums[3] = 4;

	for (int i = 4; i < 1000001; i++)
	{
		nums[i] = (nums[i - 1] + nums[i - 2] + nums[i - 3]) % 10007;
	}

	int t; // Test cases.
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		int ways = 1;

		for (int j = 0; j < n; j++)
		{
			int s;
			cin >> s;

			ways *= nums[s];
			ways = ways % 10007;
		}

		cout << ways << endl;
	}

	delete[] nums;
}
*/

//int main() {
//	int t; // Test cases.
//	cin >> t;
//
//	for (int i = 0; i < t; i++)
//	{
//		int p, n;
//		cin >> p >> n;
//
//		int beauty = 0;
//
//		for (int j = 0; j < p; j++)
//		{
//			int bi, ni;
//			cin >> bi >> ni;
//
//			if (ni < n)
//			{
//				beauty += ni * bi;
//				n -= ni;
//			}
//			else
//			{
//				beauty += n * bi;
//				n = 0;
//			}
//		}
//
//		cout << beauty << endl;
//	}
//}

//int main() {
//	// Test cases.
//
//	int t;
//	cin >> t;
//
//	for (int i = 0; i < t; i++)
//	{
//		int m, n;
//		cin >> m >> n;
//
//		int k; // Total number of lines.
//		cin >> k;
//
//		// Number of horizontal lines and vertical lines.
//		int h = 1;
//		int v = 1;
//
//		for (int j = 0; j < k; j++)
//		{
//			int x1, y1, x2, y2;
//			cin >> x1 >> y1 >> x2 >> y2;
//
//			if ((x1 == 0 && x2 == m) || (x1 == m && x2 == 0))
//			{
//				h++;
//			}
//			else
//			{
//				v++;
//			}
//		}
//
//		cout << h * v << endl;
//	}
//}

//class Solution {
//public:
//	bool isHappy(int n) {
//		cout << n << endl;
//
//		if (n == 1)
//		{
//			return true;
//		}
//		if (n == 4)
//		{
//			return false;
//		}
//
//		return isHappy(sumSquares(n));
//	}
//
//	int sumSquares(int n)
//	{
//		if (n == 0)
//		{
//			return 0;
//		}
//
//		return (n % 10) * (n % 10) + sumSquares(n / 10);
//	}
//};
//
//int main()
//{
//	Solution s;
//
//	int n;
//	cout << "Enter your test number: ";
//	cin >> n;
//
//	cout << endl << n << " is " << ((s.isHappy(n)) ? "happy" : "sad") << endl;
//}