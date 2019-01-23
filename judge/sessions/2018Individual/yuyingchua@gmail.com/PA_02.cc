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

int main() {
    int testcases;
    cin >> testcases;
    vector<int> maxStudents;
    for (int i = 1; i <= testcases; i++)
    {
        int smallbergJump;
        cin >> smallbergJump;
        int CS31options;
        int CS32options;
        cin >> CS31options;
        cin >> CS32options;
        vector<int> ClassSize31;
        vector<int> ClassSize32;
        for (int j = 0; j < CS31options; j++)
        {
            int cs31classsize;
            cin >> cs31classsize;
            ClassSize31.push_back(cs31classsize);
        }
        for (int k = 0; k < CS32options; k++)
        {
            int cs32classsize;
            cin >> cs32classsize;
            ClassSize32.push_back(cs32classsize);
        }
        int maxS = 0;
        for (int j = 0; j < CS31options; j++)
        {
            for (int k = 0; k < CS32options; k++)
            {
                int studentsTaught = ClassSize31[j] + ClassSize32[k];
                if(studentsTaught <= smallbergJump && studentsTaught > maxS)
                maxS = studentsTaught;
            }
        }
        maxStudents.push_back(maxS);
    }
    for (int i = 0; i < maxStudents.size(); i++)
        cout << maxStudents[i] << endl;
    
    
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
