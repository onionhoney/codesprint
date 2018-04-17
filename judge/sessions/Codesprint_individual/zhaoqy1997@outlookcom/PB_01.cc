#include <iostream>
using namespace std;;

int main()
{
	int numCases;
	cin>>numCases;

	while (numCases != 0)
	{
		int x, y;
		cin>>x>>y;

		int lineNum;
		cin>>lineNum;

		int countx = 0;
		int county = 0;

		while (lineNum != 0)
		{
			int p11, p12, p21, p22;
			cin>>p11>>p12>>p21>>p22;

			if (p11 == p21)
			{
				if (p11 != 0 && p11!=x)
					countx++;
			}

			if (p12 ==p22)
			{
				if (p12 != 0 && p12!=y)
					county++;
			}


			lineNum--;
		}


		cout<<(countx+1)*(county+1)<<endl;




		numCases--;
	}
}