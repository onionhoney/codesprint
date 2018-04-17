// Example program
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <algorithm>
using namespace std;

// int flowers(int n)
// {
     
// }


int maxnum(vector<int>& flowers)
{
	int max = 0;
	for(int i = 0; i < flowers.size(); i++)
	{
		if( flowers[i] > max)
		{
			max = flowers[i];
		}
	}
	return max;

}


int iterate(int arr[][50005], int size, int maxim)
{	
	int temp[1005][2];
	int num_flow = 0;
	int sum = 0;
	int maxn =0;
	std::vector<int> v;
	for(int i = 0; i < size; i++)
	{
		v.push_back(arr[i][0]);
		for(int j = 0; j < arr[i][1]; j++)
		{
			temp[i][j] = arr[i][j];
		}
	}
	while(num_flow != maxim)
	{
		maxn = maxnum(v);
		for(int i = 0; i < size; i++)
		{
			if(temp[i][0] == maxn)
			{
				if(temp[i][0] != 0)
				{
					sum += maxn;
					temp[i][0] = temp[i][0] - 1;
					num_flow += 1;
				}
				else
				{
					v.erase(std::remove(v.begin(), v.end(), maxn), v.end());
				}
			}
		}
	}
	return sum;
}

int main()
{
  
  int t;
  int counter = 0;
  std::cin>>t;
  int flowerarray [t];
  while(counter != t) {
    int p;
    int n;
    std::cout << "";
    std::cin>>p >> n;
    std::cout << "\n";
    assert(p >= 1 && p <= 1000);
    assert(n >= 1 && n <= 50000);
    std::cout << p << n << "\n";
    int counter2 = 0;
    int goodstuff [1005][50005];
    while(counter2 != p) {
        std::cout << "stuff2\n" ;
        int bi;
        int ni;
        std::cin >> bi >> ni;
        std::cout << "\n";
        assert(bi <= 1000 && ni >= 1);
        goodstuff[counter2][0] = bi;
        goodstuff[counter2][1] = ni;
        counter2 +=1;   
    }
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cout << goodstuff[i][j] << " ";
        }
        std::cout << "\n";
        
    }
    flowerarray[counter] = iterate(goodstuff, p, n);
    counter += 1;
 }   

  return 0;
}

// int main()
// {
//   int c []={1,2,3,4,5};
//   string name;
  
//  for (int i= 0; i < 5; i++){
//      std::cout<<c[i]<<endl;
//  }
//   std::cout << "What is your name? ";
//   getline (std::cin, name);
//   std::cout << "Hello, " << name << "!\n";
// }
