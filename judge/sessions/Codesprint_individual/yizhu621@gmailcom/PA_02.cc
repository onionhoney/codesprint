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
    int tc;
    cin >> tc;
    int score[tc];
    for (int i = 0; i < tc; i++)
    {
        score[i] = 0;
        int p, n;
        cin >> p >> n;
        flower flower[p];
        for (int j = 0; j < p; j++)
        {
            cin >> flower[j].score >> flower[j].number;
        }
        //cout << flower[0].score << flower[0].number;
        int k = 0;
        int a = 0;
        while (a < p && k+flower[a].number < n)
        {
            score[i] += flower[a].score * flower[a].number;
            k += flower[a].number;
            a++;
        }
        if (a < p)
            score[i] += flower[a].score * (n-k);
    }
    for (int i = 0; i < tc; i++)
        cout << score[i] << endl;
}
