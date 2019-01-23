#include <iostream>
#include <vector>

int main()
{
    int testCases;
    std::cin >> testCases;
    std::vector<int>results;
    for (int cases = 0; cases<testCases; cases++)
    {
        int result = 0;
        int elevatorTime, stopTime, stairTime, floors, people;
        std::cin >> elevatorTime >> stopTime >> stairTime >> floors >>people;
        std::vector<int> target;
        for (int i=0; i<people; i++)
        {
            int num;
            std::cin >> num;
            target.push_back(num);
        }
        
        //ELEVATOR//
        int elevatorTotal = 0;
        int pastFloor = 1;
        int currentFloor = 1;
        for (int i=0; i<target.size(); i++)
        {
            if (target[i] > currentFloor)
            {
                currentFloor = target[i];
                int dif = currentFloor - pastFloor;
                elevatorTotal+= dif*elevatorTime + stopTime;
            }
        }
        if (elevatorTotal != 0)
            elevatorTotal -= stopTime;
        
        //STAIRS//
        int stairTotal = 0;
        int stairMax = 0;
        for (int i=0; i<target.size(); i++)
        {
            if (target[i] > stairMax)
                stairTotal = i*stairTime;
        }
        
        
        //COMPARE//
        if (elevatorTotal > stairTime)
            results.push_back(stairTime);
        else
            results.push_back(elevatorTotal);
    }
    for (int i=0; i<results.size(); i++)
        std::cout << results[i] << std::endl;
    return 0;
}
