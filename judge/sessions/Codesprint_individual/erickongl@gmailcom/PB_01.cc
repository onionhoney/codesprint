#include <iostream>
using namespace std;

int main() {
	// Test cases.

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int m, n;
		cin >> m >> n;

		int k; // Total number of lines.
		cin >> k;

		// Number of horizontal lines and vertical lines.
		int h = 1;
		int v = 1;

		for (int j = 0; j < k; j++)
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;

			if ((x1 == 0 && x2 == m) || (x1 == m && x2 == 0))
			{
				h++;
			}
			else
			{
				v++;
			}
		}

		cout << h * v << endl;
	}
}

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