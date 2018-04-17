#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct Coor
{
public:
	Coor(int x, int y)
	{
		this->x = x;
		this->y = y;
		mine = false;
	}
	int x;
	int y;
	bool mine;
	bool operator==(const Coor &c) const
	{
		return x == c.x && y == c.y;
	}
};

namespace std {

	template <>
	struct hash<Coor>
	{
		std::size_t operator()(const Coor& k) const
		{

			return (k.y << 16) ^ k.x;
		}
	};

}

void addSurrounding(Coor c, int value)
{
	
}


unordered_map<Coor, int> m;

void addCoor(int x, int y)
{
	Coor c(x, y);
	auto it = m.find(c);
	if (it != m.end())
		it->second++;
	else
		m[c] = 1;
}

int main()
{
	int tests;
	cin >> tests;
	
	int total = 0;

	for (int i = 0; i < tests; i++)
	{
		m.clear();
		total = 0;

		int size_x, size_y, t, x, y;
		cin >> size_y; cin >> size_x;
		cin >> t;

		for (int j = 0; j < t; j++)
		{
			cin >> y; cin >> x; y--; x--;
			Coor c(x, y);
			if (m.find(c) != m.end())
			{
				c.mine = true;
			}

			if (y - 1 >= 0)
			{
				if (x - 1 >= 0)
				{
					addCoor(x - 1, y - 1);
				}
				if (x >= 0)
					addCoor(x, y - 1);
				if (x + 1 < size_x)
					addCoor(x + 1, y - 1);
			}

			if (x - 1 >= 0)
				addCoor(x - 1, y);
			addCoor(x, y);
			if (x + 1 < size_x)
				addCoor(x + 1, y);

			if (y + 1 < size_y)
			{
				if (x - 1 >= 0)
					addCoor(x - 1, y + 1);
				if (x >= 0)
					addCoor(x, y + 1);
				if (x + 1 < size_x)
					addCoor(x + 1, y + 1);
			}
		}
		for (auto it = m.begin(); it != m.end(); it++)
		{
			if (!it->first.mine && it->second > 0)
				++total;
		}
		cout << total << endl;
	}
}

/*
int size_x, size_y, t, x, y;
cin >> size_y; cin >> size_x;
for (int j = 0; j < size_y; j++)
for (int k = 0; k < size_x; k++)
m[j][k] = 0;

cin >> t;

for (int j = 0; j < t; j++)
{
cin >> y; cin >> x; y--; x--;
m[y][x] = -1;

if (y - 1 >= 0)
{
if (x - 1 >= 0)
m[y-1][x-1]++;
if (x >= 0)
m[y-1][x]++;
if (x + 1 < size_x)
m[y-1][x + 1]++;
}
if (x - 1 >= 0)
m[y][x - 1]++;
if (x + 1 < size_x)
m[y][x + 1]++;
if (y + 1 < size_y)
{
if (x - 1 >= 0)
m[y - 1][x - 1]++;
if (x >= 0)
m[y - 1][x]++;
if (x + 1 < size_x)
m[y - 1][x + 1]++;
}
}
for (int j = 0; j < size_y; j++)
{
for (int k = 0; k < size_x; k++)
{
if (m[j][k] > 0)
++total;
}
}*/