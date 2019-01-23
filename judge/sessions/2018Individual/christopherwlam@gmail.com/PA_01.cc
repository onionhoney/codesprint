#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <string>

using namespace std;

class Cases {
public:
	Cases() {

	}
	~Cases() {
	}
	void setJumps(int n) { numJumps = n; }
	void setOptions(int cs31, int cs32) {
		classOptionSize[0] = cs31;
		classOptionSize[1] = cs32;
	}
	void setSizes(unordered_set<int> cs31, unordered_set<int> cs32)
	{
		CS31Ops = cs31;
		CS32Ops = cs32;
	}
	void printOut() {
		cout << endl;
		cout << numJumps << endl;
		cout << classOptionSize[0] << " " << classOptionSize[1] << endl;
		for (unordered_set<int>::iterator it = CS31Ops.begin(); it != CS31Ops.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
		for (unordered_set<int>::iterator it = CS32Ops.begin(); it != CS32Ops.end(); it++) {
			cout << *it << " ";
		}
	}
	int findMaxComplement() {
		int currMax = 0;
		for (unordered_set<int>::iterator it = CS31Ops.begin(); it != CS31Ops.end(); it++) {
			int complement = numJumps - *it;
			for (int i = complement; i >= 0; i--)
			{
				unordered_set<int>::iterator findComplement = CS32Ops.find(i);
				if (findComplement != CS32Ops.end())
				{
					if(*it + *findComplement > currMax)
						currMax = *it + *findComplement;
					break;
				}
			}
		}
		return currMax;
	}
private:
	int numJumps;
	int classOptionSize[2];
	unordered_set<int> CS31Ops;
	unordered_set<int> CS32Ops;
};

int main()
{
	int testCases;
	cin >> testCases;
	vector<Cases> cases(testCases);
	for (int i = 0; i < testCases; i++)
	{
		int jumps;
		cin >> jumps;
		cases[i].setJumps(jumps);

		int sizes[2];
		cin >> sizes[0];
		cin >> sizes[1];
		cases[i].setOptions(sizes[0], sizes[1]);

		unordered_set<int> cs31;
		unordered_set<int> cs32;
		for (int j = 0; j < sizes[0]; j++)
		{
			int in;
			cin >> in;
			cs31.insert(in);
		}
		for (int j = 0; j < sizes[1]; j++)
		{
			int in;
			cin >> in;
			cs32.insert(in);
		}
		cases[i].setSizes(cs31, cs32);
	}

	for (int i = 0; i < testCases; i++)
	{
		cout << cases[i].findMaxComplement() << endl;
	}

}