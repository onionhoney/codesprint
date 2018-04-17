#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Flower
{
public:
	int beauty;
	int size;

	bool operator<(Flower a) const
	{
		return a.beauty < this->beauty;
	}

};

int maxInt(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int minInt(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int main()
{
	int tests;
	int flowers;
	int maxDraw;

	cin >> tests; 

	for (int i = 0; i < tests; i++)
	{	
		int total = 0;
		int totalDraw = 0;
		cin >> flowers; cin >> maxDraw;

		std::vector<Flower> f(flowers);
		for (int j = 0; j < flowers; j++)
		{
			Flower flower;
			cin >> flower.beauty;
			cin >> flower.size;
			f.push_back(flower);
		}
		std::sort(f.begin(), f.end());

		for (int j = 0; j < flowers && totalDraw < maxDraw; j++)
		{
			int x = minInt(maxDraw - totalDraw, minInt(maxDraw, f[j].size));
			total += f[j].beauty * x;
			totalDraw += x;
		}
		cout << total << endl;
	}

}