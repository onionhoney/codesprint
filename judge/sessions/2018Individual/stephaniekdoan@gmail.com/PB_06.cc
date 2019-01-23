#include <iostream>
#include <vector>

int main()
{
    int testCases;
    std::vector<int> results;
    std::cin >> testCases;
    for (int x=0; x<testCases; x++)
    {
        for (int rounds=0; rounds<3; rounds++)
        {
            for (int i=0; i<100; i++)
            {
                int number;
                std::cin >> number;
                if (number == 1)
                {
                    results.push_back(i);
                }
            }
        }
    }
    for (int i=0; i<results.size(); i++)
    {
        std::cout << results[i];
        if ((i+1) % 3 == 0)
            std::cout << std::endl;
        else
            std::cout << " ";
    }
}

