//
//  main.cpp
//  codesprint
//
//  Created by Kedar Thiagarajan on 1/28/17.
//  Copyright © 2017 Kedar Thiagarajan. All rights reserved.
//

using namespace std;
#include <vector>
#include <iostream>
#include <string>
#include <math.h>


class flower
{   public:
    flower(int beaut, int numbe);
    int beauty;
    int number;
    
};

void fsort(vector<flower> vec)
{
    
    for(int i =0; i < vec.size(); i++)
    {
        if(vec[i].beauty > vec[0]. beauty)
        {
            flower temp = vec[0];
            vec[0] = vec[i];
            vec[i] = temp;
        }
    }
        
}

flower::flower(int beaut, int numbe)
{
    beauty = beaut;
    number = numbe;
}
int main()
{
    int t;
    cin >> t;
    cout << endl;
    for (int t = 0; t < 100; t++)
    {
        int p, n, b, m;
        cin >> p >> n;
       
        vector<flower> vec;
        for(int j = 0; j < p; j++)
        {
            cin >> b >> m;
            flower newf = flower(b,m);
            vec.push_back(newf);
            cout << endl;
            
        }
        fsort(vec);
        
        int remainingf =  n;
        int maxbeauty = 0;
        for(int k = 0; k < vec.size() && remainingf > 0; k++)
        {
            if(remainingf-vec[k].number > 0)
            {
                maxbeauty += vec[k].number * vec[k].beauty;
                remainingf -= vec[k].number;
            }
            else
            {
                maxbeauty += remainingf * vec[k].beauty;
                break;
            }
        }
        
        cout << maxbeauty << endl;
        
    }
    
    
}