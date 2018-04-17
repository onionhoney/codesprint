//
//  main.cpp
//  CodesprintLA ProblemA
//
//  Created by Yizhu Zhang on 1/28/17.
//  Copyright © 2017 Yizhu Zhang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class flower{
public:
    int score;
    int number;
};

int main(int argc, const char * argv[]) {
    string tcline;
    getline(cin, tcline);
    int tc = stoi(tcline);
    int score = 0;
    for (int i = 0; i < tc; i++)
    {
        int p, n;
        cin >> p >> n;
        flower flower[p];
        for (int j = 0; j < p; j++)
            cin >> flower[j].score >> flower[j].number;
        int k = 0;
        int j = 0;
        while (k+flower[j].number < n)
        {
            score += flower[j].score * flower[j].number;
            k += flower[j].number;
            j++;
        }
        score += flower[j].score * (n-k);
        cout << score << endl;
    }
}
