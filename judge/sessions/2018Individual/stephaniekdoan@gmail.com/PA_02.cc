#include <iostream>
#include <string>
#include <vector>

int main()
{
    int testCases=0;
    std::cin >> testCases;
    std::vector<int> results;
    for (int test=0; test<testCases; test++)
    {
        int maxJumps;
        int cs31jumps, cs32jumps;
        std::vector<int>cs31;
        std::vector<int>cs32;
        std::cin >> maxJumps;
        std::cin >> cs31jumps >> cs32jumps;
        for (int i=0; i<cs31jumps; i++)
        {
            int input;
            std::cin >> input;
            cs31.push_back(input);
        }
        for (int i=0; i<cs32jumps; i++)
        {
            int input;
            std::cin >> input;
            cs32.push_back(input);
        }
        int minDif = maxJumps;
        int result = 0;
        for (int i=0; i<cs31.size(); i++)
        {
            for (int x=0; x<cs32.size(); x++)
            {
                int sum = cs31[i] + cs32[x];
                int dif = maxJumps - sum;
                if (sum <= maxJumps && dif < minDif)
                {
                    minDif = dif;
                    result = sum;
                }
            }
        }
        results.push_back(result);
    }
    for (int i=0; i<results.size(); i++)
        std::cout << results[i] << std::endl;
    return 0;
}
