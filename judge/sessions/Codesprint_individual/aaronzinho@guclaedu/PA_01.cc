#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	std::map<int, int> beauty_range;
	std::vector<int> key, sc;
	int test_num, flowers, tot, reps, i = 0;
	cin >> test_num;
	sc.resize(test_num);
	while (i < test_num)
	{
		cin >> flowers >> reps;
		int j = 0, b, r;
		key.resize(flowers);
		while (j < flowers)
		{
			cin >> b;
			cin >> r;
			beauty_range[b] = r;
			key[j] = b;
			++j;
		}
		sort(key.begin(), key.end());
		reverse(key.begin(), key.end());
		int dec = reps;
		int tot_reps = 0;
		for (int h = 0; h < key.size(); h++)
			tot_reps += beauty_range[key[h]];
		int k = 0;
		while (dec != 0 && tot_reps != 0)
		{
			if (beauty_range[key[k]] > 0) {
				beauty_range[key[k]] -= 1;
			}
			else {
				k += 1;
				beauty_range[key[k]] -= 1;
			}
			//cout << beauty_range[key[k]] << '\n';
			sc[i] += key[k];
			dec -= 1;
			tot_reps -= 1;
		}
		i++;
	}
	int a = 0;
	while (a < test_num)
		cout << sc[a++] << '\n';
	system("pause");

	return 0;
}