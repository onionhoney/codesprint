//
//  main.cpp
//  CodeSprintLA2018
//
//  Created by Sky Maverick on 5/20/18.
//  Copyright © 2018 Yu-Ying Chua. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;



//int factorial(int n)
//{
//    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
//}

int main() {
//    //Prob 3
//    int testcases;
//    cin >> testcases;
//    vector<int> numCombos;
//    for (int i = 1; i <= testcases; i++)
//    {
//        vector<vector<int>> numRoomCombo;
//        vector<vector<int>> alreadyMadeCombo;
//        vector<vector<int>> totalCombos;
//
//        int numRooms = 0;
//        cin >> numRooms;
//        int currPassageWays = 0;
//        cin >>currPassageWays;
//        for (int i = 0; i <= currPassageWays; i++)
//        {
//            int Room1;
//            int Room2;
//            cin >> Room1;
//            cin >> Room2;
//            vector<int> roomConnect;
//            roomConnect.push_back(Room1);
//            roomConnect.push_back(Room2);
//            alreadyMadeCombo.push_back(roomConnect);
//            roomConnect.clear();
//        }
//        int Room1;
//        int Room2;
//        for (int n = 1; n < numRooms; n++)
//        {
//            Room1 = n;
//            Room2 = n+1;
//            vector<int> roomConnect;
//            roomConnect.push_back(Room1);
//            roomConnect.push_back(Room2);
//            totalCombos.push_back(roomConnect);
//            roomConnect.clear();
//        }
//        int numNewCombosPoss= totalCombos.size();
//        for (int p = 0; p < totalCombos.size(); p++)
//        {
//            for (int o = 0; o < alreadyMadeCombo.size(); o++)
//            {
//                if (totalCombos[p] == alreadyMadeCombo[o])
//                {
//                    numNewCombosPoss--;
//                }
//            }
//        }
//        int numNewConnectionsPoss = factorial(numNewCombosPoss);
//        numCombos.push_back(numNewConnectionsPoss);
//    }
//    for (int u = 0; u < numCombos.size(); u++)
//    {
//        cout << numCombos[u] << endl;
//    }

    //Prob 2
    int testcases;
    cin >> testcases;

    vector<int> LockNumbers;
    for (int i = 1; i <= testcases; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            int number = 0;
        for (int i = 0; i <= 99; i++)
        {
            int result;
            cin >> result;
            if (result == 1)
            {
                LockNumbers.push_back(number);
            }
            number++;
        }
        }
    }
    int rowcount = 0;
    for (int i = 0; i < LockNumbers.size(); i++)
    {
        rowcount++;
        cout << LockNumbers[i];
        if (rowcount == 3)
        {
            cout << endl;
            rowcount = 0;
        }
        else
            cout << " ";
    }
    
    
//    //Prob1
//    int testcases;
//    cin >> testcases;
//    vector<int> maxStudents;
//    for (int i = 1; i <= testcases; i++)
//    {
//        int smallbergJump;
//        cin >> smallbergJump;
//        int CS31options;
//        int CS32options;
//        cin >> CS31options;
//        cin >> CS32options;
//        vector<int> ClassSize31;
//        vector<int> ClassSize32;
//        for (int j = 0; j < CS31options; j++)
//        {
//            int cs31classsize;
//            cin >> cs31classsize;
//            ClassSize31.push_back(cs31classsize);
//        }
//        for (int k = 0; k < CS32options; k++)
//        {
//            int cs32classsize;
//            cin >> cs32classsize;
//            ClassSize32.push_back(cs32classsize);
//        }
//        int maxS = 0;
//        for (int j = 0; j < CS31options; j++)
//        {
//            for (int k = 0; k < CS32options; k++)
//            {
//                int studentsTaught = ClassSize31[j] + ClassSize32[k];
//                if(studentsTaught <= smallbergJump && studentsTaught > maxS)
//                maxS = studentsTaught;
//            }
//        }
//        maxStudents.push_back(maxS);
//    }
//    for (int i = 0; i < maxStudents.size(); i++)
//        cout << maxStudents[i] << endl;
    
    
//WarmUp
//    int n;
//    cin >> n;
//    int output;
//    int a;
//    std::vector<int> outputVec;
//    for (int I = 1; I <= n; I++)
//    {
//        cin >> a;
//        int fibonacci = 0;
//        if (a == 1 || a == 2)
//        {
//            fibonacci = 1;
//            outputVec.push_back(1);
//        }
//        else
//        {
//            int preceding1 = 1;
//            int preceding2 = 1;
//            for (int I = 3; I <= a; I++)
//            {
//                fibonacci = preceding1 + preceding2;
//                preceding1 = preceding2;
//                preceding2 = fibonacci;
//            }
//            outputVec.push_back(fibonacci % 1000000007);
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        cout << outputVec[i] << endl;
//    }

}
